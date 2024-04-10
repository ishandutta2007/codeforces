#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
 
using namespace std;
 
struct edge
{
    int s, e;
    long long x;
};
bool operator< (const edge &x, const edge &y) { return x.x < y.x; }
 
int par[101010];
int sz[101010];
vector<pii> qr[101010];
long long ans[303030];
 
int fnd(int x) { return (x == par[x] ? x : par[x] = fnd(par[x])); }
void uni(int x, int y, long long p)
{
    x = fnd(x), y = fnd(y);
    if(x == y) return;
 
    if(sz[x] < sz[y]) swap(x, y);
    par[y] = x, sz[x] += sz[y];
 
    for(auto &i : qr[y])
    {
        if(!ans[i.ss])
        {
            if(fnd(i.ff) == x) ans[i.ss] = p;
            else qr[x].push_back(i);
        }
    }
 
    vector<pii>().swap(qr[y]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<pii> gph[n];
    vector<edge> eg;
    for(int i = 0; i < m; ++i)
    {
        int x, y, p; cin >> x >> y>> p; --x; --y;
        gph[x].push_back({y, p});
        gph[y].push_back({x, p});
        eg.push_back({x, y, p});
    }
 
    long long dis[n]; for(auto &i : dis) i = -1;
    priority_queue<pll, vector<pll>, greater<pll>> PQ;
    for(int i = 0; i < k; ++i) PQ.push({0, i});
    while(!PQ.empty())
    {
        pll tmp = PQ.top(); PQ.pop();
        if(dis[tmp.ss] != -1) continue;
        dis[tmp.ss] = tmp.ff;
        for(auto &x : gph[tmp.ss]) PQ.push({tmp.ff + x.ss, x.ff});
    }
 
    for(auto &i : eg) i.x += dis[i.s] + dis[i.e];
    sort(eg.begin(), eg.end());
 
    for(int i = 0; i < q; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        qr[x].push_back({y, i});
        qr[y].push_back({x, i});
    }
 
    for(int i = 0; i < n; ++i) par[i] = i, sz[i] = 1;
    for(auto &i : eg) uni(i.s, i.e, i.x);
 
    for(int i = 0; i < q; ++i) cout << ans[i] << '\n';
    return 0;
}