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

ll a[200002];

void solve()
{
    ll n, k; cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n <= k)
    {
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += a[i];
        ans += (n-1)*n/2;
        ans += (k-n)*n;
        cout << ans << "\n";
    }
    else
    {
        ll ans = 0;
        for(int i=2;i<=n;i++) a[i] += a[i-1];
        for(int i=k;i<=n;i++) ans = max(ans, a[i] - a[i-k]);
        cout << ans+(k-1)*k/2 << "\n";
    }
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