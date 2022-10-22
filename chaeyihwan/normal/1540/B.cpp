#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

vector<int> adj[202];
ll fact[402], ifact[402], pw[202], C[202];
ll dist1[202], dist2[202];
ll comb[402][402];
int chk[202];

ll inv(ll x)
{
    ll ans = 1; int k = 0;
    while((1LL << k) <= mod-2)
    {
        if((1LL << k) & (mod - 2))
        {
            ans = (ans * x)%mod;
        }
        x = (x * x)%mod;
        k++;
    }
    return ans;
}

void dfs(int x, int y, int p, int a, int b)
{
    if(x == y) a = 1;
    for(int i : adj[x])
    {
        if(i == p) continue;
        if(b == -1) dist1[i] = dist1[x] + 1;
        else dist2[i] = dist2[x] + 1;
        dfs(i, y, x, a, b);
    }
    if(a == 1) chk[x] = b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<n;i++)
    {
        int s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    pw[0] = 1;
    ll inv2 = inv(2);
    for(int i=1;i<=400;i++) pw[i] = (pw[i-1] * inv2)%mod;

    for(int i=0;i<=400;i++)
    {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%mod;
        }
    }
    for(int i=0;i<=400;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            comb[i][j] = (comb[i][j] + comb[i][j+1])%mod;
        }
    }

    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=1;k<=n;k++) chk[k] = 0;
            dist1[i] = 0, dist2[j] = 0;
            dfs(i, j, -1, 0, -1);
            dfs(j, i, -1, 0, -2);
            for(int k=1;k<=n;k++)
            {
                if(chk[k] == 0)
                {
                    ll d = dist1[k] + dist2[k] - dist1[j];
                    dist1[k] -= d/2;
                    dist2[k] -= d/2;
                    ll tmp = comb[dist1[k] + dist2[k] - 1][dist2[k]] * pw[dist1[k] + dist2[k] - 1];
                    tmp %= mod;
                    ans += tmp;
                    ans %= mod;
                }
                if(chk[k] == -1)
                {
                    ans += 1;
                    ans %= mod;
                }
            }
        }
    }
    ans *= inv(n);
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans;
}