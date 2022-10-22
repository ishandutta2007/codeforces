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
const ll mod = 998244353;

ll a[100002];
ll pw[100002];
ll fac[100002];

ll inv(ll x)
{
    int h = 0; ll ret = 1;
    while((1LL << h) <= mod - 2)
    {
        if((1LL << h) & (mod - 2)) ret = (ret * x)%mod;
        x = (x * x)%mod;
        h++;
    }
    return ret;
}

ll comb(int n, int k)
{
    ll tmp = fac[n] * inv(fac[k]);
    tmp %= mod;
    tmp = (tmp * inv(fac[n-k]))%mod;
    return tmp;
}

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    int l = 1, r = n;
    ll ans = 1;
    ll sum = 0;
    for(int i=1;i<=n;i++)
        sum += a[i];
    
    if(sum == 0)
    {
        cout << pw[n-1] << "\n";
        return;
    }
    
    if(a[1] == 0 && a[n] == 0)
    {
        ll lef = 0, rig = 0;
        while(a[l] == 0)
        {
            l++;
            lef++;
        }
        while(a[r] == 0)
        {
            r--;
            rig++;
        }
        
        if(l > r) ans = (ans * pw[lef-1])%mod;
        else
        {
            ll tmp = 0;
            for(int j=0;j<=min(lef, rig);j++)
            {
                tmp = (tmp + comb(lef, j) * comb(rig, j))%mod;
            }
            ans = (ans * tmp)%mod;
        }
    }
    
    while(l < r)
    {
        ll lsum = a[l];
        ll rsum = a[r];
        while(l < r && lsum != rsum)
        {
            if(lsum < rsum)
            {
                l++;
                lsum += a[l];
            }
            else
            {
                r--;
                rsum += a[r];
            }
        }
        
        if(l >= r) break;
        
        ll lef = 1, rig = 1;
        l++; r--;
        if(l > r)
        {
            ans = (ans * 2)%mod;
            break;
        }
        while(a[l] == 0)
        {
            l++;
            lef++;
        }
        while(a[r] == 0)
        {
            r--;
            rig++;
        }
        
        if(l > r) ans = (ans * pw[lef])%mod;
        else
        {
            ll tmp = 0;
            for(int j=0;j<=min(lef, rig);j++)
            {
                tmp = (tmp + comb(lef, j) * comb(rig, j))%mod;
            }
            ans = (ans * tmp)%mod;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    pw[0] = 1;
    for(int i=1;i<=100000;i++) pw[i] = (pw[i-1] * 2)%mod;
    fac[0] = 1;
    for(int i=1;i<=100000;i++) fac[i] = (fac[i-1] * i)%mod;
    while(t--) solve();
}