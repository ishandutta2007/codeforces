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
    int n;
    cin >> n;
    int a[10] = {};
    for (int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        a[t]++;
    }
    if (a[0]==0)
    {
                cout << -1;
                return 0;
    }
    int sum = 0;
    for (int i=0;i<10;i++)
        sum += (i*a[i]);
    if (sum%3!=0)
    {
                 bool found = false;
                 for (int i=1;i<10;i++)
                     if ((sum-i)%3==0 && a[i]>0)
                     {
                                      a[i]--;
                                     found=true;
                                       break;
                     }
                 if (!found)
                 for (int i=1;i<10 && !found;i++)
                     for (int j=1;j<10;j++)
                         if ((i==j && a[i]>1 || i!=j && a[i]>0 && a[j]>0)&&((sum-i-j)%3==0))
                         {
                                   a[i]--;
                                   a[j]--;
                                   break;
                         }
    }
    bool end = true;
    for (int i=1;i<10;i++)
        if (a[i]>0)
           end = false;
    if (end)
       cout << 0;
    else
        for (int i=9;i>=0;i--)
            for (int j=0;j<a[i];j++)
                cout << i;
   // system("pause");
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