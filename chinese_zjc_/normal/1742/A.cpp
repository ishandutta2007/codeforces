// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T,a,b,c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin>>a>>b>>c;
        std::cout<<(std::max({a,b,c})<<1==(a+b+c)?"YES":"NO")<<std::endl;
    }
    return 0;
}