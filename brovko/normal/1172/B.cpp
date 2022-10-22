#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;
const int MOD=998244353;

int n, u, v, ans, fact[200005];
vector <int> g[200005];

int mul(int x, int y)
{
    return x*y%MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ans=n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fact[0]=1;
    for(int i=1;i<200005;i++)
        fact[i]=mul(i, fact[i-1]);

    for(int i=0;i<n;i++)
        ans=mul(ans, fact[g[i].size()]);
    cout << ans;
}