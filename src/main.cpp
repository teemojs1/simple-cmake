// #include "static/Hello.h"

// int main(int argc, char *argv[])
// {
//     Hello hi;
//     hi.print();
//     return 0;
// }
#include "vlcpp/vlc.hpp"
#include <thread>
#include <iostream>

int main(int ac, char** av)
{
    if (ac < 2)
    {
        std::cerr << "usage: " << av[0] << " <file to play>" << std::endl;
        return 1;
    }
    std::string url = "https://multiplatform-f.akamaihd.net/i/multi/will/bunny/big_buck_bunny_,640x360_400,640x360_700,640x360_1000,950x540_1500,.f4v.csmil/master.m3u8";


    auto instance = VLC::Instance(0, nullptr);
    // auto media = VLC::Media(instance, av[1], VLC::Media::FromPath);
    auto media = VLC::Media(instance, av[1], VLC::Media::FromPath);
    auto mp = VLC::MediaPlayer(media);
    mp.play();
    std::this_thread::sleep_for( std::chrono::seconds( 10 ) );
#if LIBVLC_VERSION_INT >= LIBVLC_VERSION(4, 0, 0, 0)
    mp.stopAsync();
#else
    mp.stop();
#endif
}