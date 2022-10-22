#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

ll mysqrt(ll x)
{
    ll l = 1, r = 1000000000;
    while(l < r)
    {
        ll mid = (l + r + 1)/2;
        if(mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve()
{
    ll L, R; cin >> L >> R;
    ll sl = mysqrt(L);
    ll sr = mysqrt(R);
    
    ll ans = (sr - sl + 1) * 3;
    if(sl * sl < L) ans--;
    if(sl * (sl + 1) < L) ans--;
    if((sl + 1) * (sl + 1) - 1 < L) ans--;
    
    if(sr * sr > R) ans--;
    if(sr * (sr + 1) > R) ans--;
    if((sr+1) * (sr+1) - 1 > R) ans--;
    
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}