#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n,m;
        std::cin >> n >> m;
        int x[m],y[3];
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
        }
        if(n <= m)
        {
            std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "YES" << std::endl;
        }
        
    }
    return 0;
}