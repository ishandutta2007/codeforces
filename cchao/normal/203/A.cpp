#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int x,t,a,b,da,db;
    cin >> x >> t >> a >> b >> da >> db;
    for(int j = 0 ; j < t; j ++)
    {
        for(int k = 0 ;  k < t; k++)
        {
            //printf("Try %d\n", (a+b) - da * j - db * k);
            if( (a + b) - da * j - db * k == x  || a - da * j == x || b - db * k == x || x == 0)
            {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}