#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int ans;
        if(n >= 1900) ans =  1;
        if(n < 1900 && n >= 1600 ) ans =  2;
        if(n <= 1599 && n >= 1400 ) ans =  3;
        if(n <= 1399) ans =  4; 
        std::cout << "Division " << ans << std::endl;
    }
    return 0;
}