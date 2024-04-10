#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;

struct edge{
    int v, w;
};

vector<edge> g[maxn];

int r[maxn];
int n, m, k;
long long d[maxn]; int p[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back((edge){b, c});
        g[b].push_back((edge){a, c});
    }
    d[1] = 0;
    for(int i = 2; i <= n; ++i) d[i] = 1000000000000000000LL;

    memset(p, -1, sizeof p);
    memset(r, -1, sizeof r);

    queue<int> q;
    bitset<maxn> inq;
    q.push(1);
    int ans = 0;
    
    for(int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        if(r[a] == -1) {
            d[a] = b;
            q.push(a);
            inq.set(a);
        }
        else {
            ans++;
            d[a] = min(d[a], (long long)b);
        }
        r[a] = 1;
        p[a] = a;
    }

    p[1] = maxn;
    while(q.size()) {
        int x = q.front(); q.pop(); inq.reset(x);
        for(int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].v, w = g[x][i].w;
            if(d[x] + w < d[y] || (d[x] + w == d[y] && p[y] == y)) {
                d[y] = d[x] + w;
                p[y] = p[x];
                if(!inq.test(y)) {
                    inq.set(y);
                    q.push(y);
                }
            }
        }
    }

    for(int i = 2; i <= n; ++i) {
        if(r[i] >= 0 && p[i] != i) ans++;
    }

    cout << ans << endl;
    return 0;
}