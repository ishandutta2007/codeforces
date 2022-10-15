#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e18;
int n;
ll v[N];
ll mx[N];
bool u[N];
vector<int> g[N];

ll mult(ll a, ll b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }
    if (a == INF || b == INF)
    {
        return INF;
    }
    ll p = a * b;
    if (p % a == 0 && p / a == b && p <= INF)
    {
        return p;
    }
    else
    {
        return INF;
    }
}

ll cmmmc(ll a, ll b)
{
    if (a == INF || b == INF)
    {
        return INF;
    }
    return mult(a / __gcd(a, b), b);
}

ll dfs(int a)
{
    vector<int> kids;
    u[a] = 1;
    ll s = 1;
    for (auto &b : g[a])
    {
        if (u[b] == 0)
        {
            kids.push_back(b);
            s = cmmmc(s, dfs(b));
        }
    }
    if (!kids.empty())
    {
        s *= (int) kids.size();
        ll lim = 0;
        ll mn = mx[kids[0]];
        for (int i = 1; i < (int) kids.size(); i++)
        {
            mn = min(mn, mx[kids[i]]);
        }
        lim = mn * (ll) kids.size();
        lim /= s;
        lim *= s;
        mx[a] = lim;
    }
    else
    {
        mx[a] = v[a];
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll sol = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sol += v[i];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << sol - mx[1] << "\n";
}