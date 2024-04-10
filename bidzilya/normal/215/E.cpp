#include <algorithm>
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
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1000000007;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (long long)1e18;

ll l,r;
ll c[64];

void calc(ll x,ll & alen,ll & ans)
{
           if (x<=1)
                    return;
           int len=0;
           int b[64];
           while (x>0)
           {
                 b[len] = x%2;
                 len++;
                 x /= 2;
           }
           for (int i=0,j=len-1;i<j;i++,j--)
               swap(b[i],b[j]);
           ll xx = 0;
           for (int i=1;i<len;i++)
           {
               alen += ((1LL<<(i-1))-c[i]);
               xx = xx*2+b[i-1];
               if (len%i==0)
               {
                            for (int j=i;j<len;j++)
                                if (b[j]>b[j%i])
                                {
                                   ans++;
                                   break;
                                }else
                                if (b[j]<b[j%i])
                                   break;
                            ll a1=0,a2=0;
                            calc(xx,a1,a2);
                            ans += (xx-a2-(1LL<<(i-1)));
               }
           }
}           

ll calc2(ll x)
{
            ll a1=0,a2=0;
            calc(x,a1,a2);
            return (a1+a2);
}

int main()
{
    c[1]=1;
    for (int i=2;i<=63;i++)
    {
        c[i] = 1LL<<(i-1);
        for (int j=1;j<i;j++)
            if (i%j==0)
               c[i] -= c[j];
    }
    ll l,r;
    cin >> l >> r;
    cout << calc2(r+1)-calc2(l) << endl;
   // system("pause");
    return 0;
}