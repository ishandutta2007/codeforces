#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
using namespace std;

typedef long long ll;
const ll MD = 10007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;
template<typename T>T gcd(T, T);

int main()
{
    int n,m;
    cin >> n >> m;
    int ans = 0;
    for (int a=0;a*a<=n;a++)
    {
        int b = n - a*a;
        if (a+b*b==m)
           ans++;
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}

/**************************************************/
template<typename T>T gcd(T x, T y)
{
                 while (x>0 && y>0)
                       if (x>=y)
                          x %= y;
                       else
                           y %= x;
                 return (x+y);
}