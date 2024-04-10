#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll a[200002], fact[200002];
ll inv(ll x)
{
    ll ans = 1; int k = 0;
    while((1LL<<k) <= mod-2)
    {
        if((1LL << k) & (mod-2))
        {
            ans = (ans * x)%mod;
        }
        x = (x * x)%mod;
        k++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    fact[0] = 1;
    for(int i=1;i<=200000;i++) fact[i] = (fact[i-1] *i)%mod;

    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        pair<int, int> M = {0, 0};
        for(int i=1;i<=n;i++)
        {
            if(M.first == a[i]) M.second++;
            else if(M.first < a[i]) M = {a[i], 1};
        }

        int cnt = 0;
        for(int i=1;i<=n;i++) if(a[i] == M.first - 1) cnt++;

        if(M.second > 1) cout << fact[n] << "\n";
        else if(cnt == 0) cout << "0\n";
        else cout << ((fact[n] * cnt)%mod * inv(cnt+1))%mod << "\n";
    }
}