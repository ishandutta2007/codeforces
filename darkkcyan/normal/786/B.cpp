#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {

#define maxn 101010
int n, q, s;
ve<ii> gr[maxn * 5];

void prebuild() {
    rep(i, n) {
        gr[i + n].push_back(ii(0, i + 4 * n));
        gr[i + 4 * n].push_back(ii(0, i + 3 * n));
    }
    for (int i = n - 1; i > 0; --i) {
        gr[i].push_back(ii(0, i << 1));
        gr[i].push_back(ii(0, i << 1 | 1));
        
        gr[(i << 1) + 2 * n].push_back(ii(0, i + 2 * n));
        gr[(i << 1 | 1) + 2 * n].push_back(ii(0, i + 2 * n));
    }
}

void addedge1(int u, int v, int w) {
    gr[u + 4 * n].push_back(ii(w, v + 4 * n));
}

void addedge2(int l, int r, int u, int w) {
    u += n * 4;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1 ) gr[u].push_back(ii(w, l++));
        if (~r & 1) gr[u].push_back(ii(w, r--));
    }
}

void addedge3(int l, int r, int u, int w) {
    u += 4 * n;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1 ) gr[l++ + 2 * n].push_back(ii(w, u));
        if (~r & 1) gr[r-- + 2 * n].push_back(ii(w, u));
    }
}

ve<long> dst;
#define ll pair<long, long> 
priority_queue<ll, ve<ll>, greater<ll> > pq;
void sssp(int s) {
    dst.assign(5 * n, inf(long));
    s += n * 4; pq.push(ll(0, s));
    dst[s] = 0;
    while (sz(pq)) {
        int u = pq.top().yy;
        long d = pq.top().xx;
        //clog << u << ' ' << d << ' ' << dst[u] << endl;
        pq.pop();
        if (dst[u] < d) continue;
        for (auto v : gr[u]) {
            long nd = d + v.xx;
            if (dst[v.yy] <= nd) continue;
            pq.push(ll(nd, v.yy));
            dst[v.yy] = nd;
        }
    }
    for (auto& i: dst) if (i == inf(long)) i = -1;
}


int main() {
    cin >> n >> q >> s; --s;
    prebuild();
    while (q--) {
        int t, v, u, l, r, w; cin >> t >> v;
        if (t == 1) cin >> u >> w, addedge1(--v, --u, w);
        else {
            cin >> l >> r >> w;
            if (t == 2) addedge2(--l, --r, --v, w);
            else addedge3(--l, --r, --v, w);
        }
    }
    sssp(s);
    for (int i = n * 4; i < 5 * n; ++i) cout << dst[i] << ' '; 
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Sol::main();
}