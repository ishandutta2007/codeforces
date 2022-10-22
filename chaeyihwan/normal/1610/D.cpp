#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll a[200002];
ll pw[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    ll ans = 0;
    pw[0] = 1;
    for(int i=1;i<=n;i++)
    {
        pw[i] = (pw[i-1] * 2)%mod;
    }
    ans = pw[n] - 1;
    for(int k=1;k<=30;k++)
    {
        ll M = (1<<k);
        ll cnt1 = 0, cnt2 = 0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%M == 0) cnt1++;
            if(a[i]%(M*2) == 0) cnt2++;
        }

        if(cnt1 == 0) break;
        if(cnt1 == cnt2) continue;
        ans -= pw[cnt1-1];
        ans %= mod;
    }
    ans += mod;
    ans %= mod;
    cout << ans;
}