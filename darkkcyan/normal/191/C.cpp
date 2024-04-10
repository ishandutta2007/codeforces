#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()

namespace Solution {

#define maxn 201010 
int n;
vi gr[maxn];
int cnt[maxn], link[maxn], d[maxn], dad[maxn];
void dfs(int u) {
    //clog << "OK " << u << endl;
    cnt[u] = 1;
    d[u] = d[dad[u]] + 1;
    link[u] = -1;
    for (int i = 0; i < sz(gr[u]); ++i) {
        int v = gr[u][i];
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
        if (link[u] == -1 or cnt[link[u]] < cnt[v]) link[u] = v;
        cnt[u] += cnt[v];
    }
}

queue<int> qu;
int chain[maxn], pos[maxn], head[maxn];

void hld() {
    d[0] = -1;
    dad[0] = 0;
    dfs(0);
    int c = 0;
    for (qu.push(0); sz(qu); qu.pop()) {
        int u = qu.front();
        for (int i = u; i != -1; i = link[i]) {
            pos[i] = c;
            head[i] = u;
            chain[c++] = i;
            for (int f = 0; f < sz(gr[i]); ++f) {
                int v = gr[i][f];
                if (d[v] > d[i] and v != link[i]) qu.push(v);
            }
        }
        c++;  // one addition space for BIT range update
    }
}

struct BIT {
    ve<long> d;
    void resize(int n) { d.assign(n + 1, 0); }
    long operator[](int i) {
        long ans = 0; for (++i; i > 0; i -= i & -i) ans += d[i]; return ans;
    }
    void operator()(int i, int v) {
        for (++i; i < sz(d); i += i & -i) d[i] += v;
    }
    void rangeupdate(int l, int r, int val) {
        (*this)(l, val);
        (*this)(r + 1, -val);
    }
} bit;

long gettrueval(int i) {
    return bit[pos[i]] - bit[pos[head[i]] - 1];
}

void query(int u, int v) {
    while (head[u] != head[v]) {
        //clog << u << ' ' << v << endl;
        if (d[head[u]] < d[head[v]]) swap(u, v);
        bit.rangeupdate(pos[head[u]], pos[u], 1);
        u = dad[head[u]];
    }
    //clog << u << ' ' << v << endl;
    if (d[u] > d[v]) swap(u, v);
    bit.rangeupdate(pos[u] + 1, pos[v], 1);
}

ii order[maxn];
int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
        order[i] = ii(u, v);
    }
    hld();
    int m; cin >> m;
    bit.resize(maxn);
    while (m--) {
        int u, v; cin >> u >> v; --u, --v;
        query(u, v);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u = order[i].xx;
        if (d[u] < d[order[i].yy]) u = order[i].yy;
        cout << gettrueval(u) << ' ';
    }
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Solution::main();
}