#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a,b,c;
            std::cin >> a >> b >> c;
            if(a+b==c || a+c==b || b+c==a)
            {
                std::cout << "YES" << std::endl;
            }
            else
            {
                std::cout << "NO" << std::endl;
            }
        }
    return 0;
}