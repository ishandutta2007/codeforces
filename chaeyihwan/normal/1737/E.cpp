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
const ll mod = 1e9 + 7;

ll pw(ll x, ll y)
{
    ll ans = 1; int k = 0;
    while((1LL << k) <= y)
    {
        if((1LL << k) & y) ans = (ans * x)%mod;
        x = (x * x)%mod;
        k++;
    }
    return ans;
}

ll inv(ll x)
{
    return pw(x, mod - 2);
}

ll P[1000002];

void solve()
{
    int n; cin >> n;
    for(int i=n/2+1;i<=n;i++) P[i] = 1;
    P[n/2] = (1 - inv(pw(2, n/2-1)) + mod)%mod;
    for(int i=n/2-1;i>=1;i--)
    {
        P[i] = P[i+1]%mod;
        P[i] -= (inv(pw(2, i)) * P[2*i])%mod;
        P[i] -= (inv(pw(2, i+1)) * P[2*i+1])%mod;
        
        P[i] %= mod;
        P[i] += mod;
        P[i] %= mod;
    }
    
    for(int i=1;i<n;i++)
    {
        cout << (inv(pw(2, (i+1)/2)) * P[i])%mod << "\n";
    }
    cout << inv(pw(2, (n-1)/2)) << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}