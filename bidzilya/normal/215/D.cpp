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

int main()
{
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    for (int i=0;i<n;i++)
    {
        ll t,T,x,cost;
        cin >> t >> T >> x >> cost;
        ll kmax = T-t;
        if (kmax<=0)
           ans += (cost+x*m);
        else
        if (kmax>=m)
           ans += cost;
        else
        {
            ll tmin = cost+x*m;
            ll cnt = m/kmax;
            if (m%kmax!=0)
               cnt++;
            tmin = min(tmin,cost*cnt);
            ans += tmin;
        }
    }
    cout << ans << endl;
   // system("pause");
    return 0;
}