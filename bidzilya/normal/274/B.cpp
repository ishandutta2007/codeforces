#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n;
vector<vector<int> > g;
ll c[111111];

pll go(int v, int pr)
{
    pll res(0,0);
    vector<ll> ap, am;
    for (int i=0; i<g[v].size(); i++)
    {
        int u = g[v][i];
        if (u!=pr)
        {
            pll tmp = go(u,v);
            ap.push_back(tmp.first);
            am.push_back(tmp.second);
        }
    }
    if (ap.size()>0)
        sort(ap.begin(), ap.end());
    if (am.size()>0)
        sort(am.begin(), am.end());
    ll buf = 0;
    for (int i=0; i<ap.size(); i++)
    {
        ll dx = ap[i]-buf;
        res.first += dx;
        buf = ap[i];
    }
    buf = 0;
    for (int i=0; i<am.size(); i++)
    {
        ll dx = am[i]-buf;
        res.second += dx;
        buf = am[i];
    }

    c[v] = c[v] + res.first - res.second;
    if (c[v] < 0)res.first += abs(c[v]);
    if (c[v] > 0)res.second += c[v];
    return res;
}

int main()
{
    cin >> n;
    g.resize(n);
    for (int i=0; i<n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=0; i<n; i++)cin >> c[i];
    pll ans = go(0,0);
    cout << ans.first + ans.second << endl;
    return 0;
}