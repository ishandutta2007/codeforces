#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n,divnum = 100000,sumfirst, sumsecond;
        int a[7];
        std::cin >> n;
        for (int i = 0; i < 6; i++) {
            a[i] = n / divnum;
            n %= divnum;
            divnum = divnum / 10;
        }
        sumfirst = a[0] + a[1] + a[2];
        sumsecond = a[3] + a[4] + a[5];
        if(sumfirst == sumsecond)
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;;
        }
        
        
      
        
    }

    return 0;
}