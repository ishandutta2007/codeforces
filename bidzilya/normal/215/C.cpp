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

int n,m;

ll calc(int a,int b,int s)
{
            if (a*b<s)
               return 0;
            if (a*b==s)
               return 2LL*(a/2+1)*(b/2+1) - 1;
            s = a*b-s;
            if (s%4!=0)
               return 0;
            s /= 4;
            ll res = 0;
            for (int c=1;c<=a/2;c++)
                if (s%c==0)
                {
                           int d = s/c;
                           if (d<=b/2)
                              res += 2;
                }
            return res;    
}

int main()
{
    int s;
    cin >> n >> m >> s;
    ll ans = 0;
    for (int a=1;a<=m;a += 2)
        for (int b=1;b<=n;b += 2)
            ans += (calc(a,b,s)*(n-b+1)*(m-a+1));
    cout << ans << endl;
    
  //  system("pause");
    return 0;
}