#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500005;
const int kMagic = 256;

int Parent[kMaxN], D[kMaxN];
bool Viz[kMaxN];
vector<pair<int, int>> bad;
vector<int> G[kMaxN];

void DFS(int node, int par, int depth) {
    Parent[node] = par;
    Viz[node] = true;
    D[node] = depth;

    for (auto vec : G[node]) {
        if (!Viz[vec]) {
            DFS(vec, node, depth + 1);
        } else if (D[vec] < D[node] - 1) {
            int lo = vec, hi = vec;

            for (int at = node; at != vec; at = Parent[at]) {
                lo = min(lo, at);
                hi = max(hi, at);
            }
            
            bad.emplace_back(lo, hi);
        }
    }
}

struct Query { int l, r, i; };

vector<pair<int, int>> Prune(vector<pair<int, int>> V) {
    sort(V.begin(), V.end());
    vector<pair<int, int>> W;
    for (auto x : V) {
        while (W.size() && W.back().second >= x.second)
            W.pop_back();
        W.push_back(x);
    }
    return W;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].push_back(b); G[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (!Viz[i]) {
            DFS(i, -1, 0);
        }
    }
    
    bad = Prune(bad);
    vector<int> left(n), right(n);
/*
    for (auto x : bad) cerr << x.first << ":" << x.second << " ";
    cerr << endl;
*/
    int at = -1;
    for (int i = 0; i < n; ++i) {
        while (at + 1 < (int)bad.size() && bad[at + 1].second <= i) {
            ++at;
        }
        if (at == -1) left[i] = -1;
        else left[i] = bad[at].first;
    }

    reverse(bad.begin(), bad.end());
    at = -1;
    for (int i = n - 1; i >= 0; --i) {
        while (at + 1 < (int)bad.size() && bad[at + 1].first >= i) {
            ++at;
        }
        if (at == -1) right[i] = n;
        else right[i] = bad[at].second;
    }
/*
    for (int i = 0; i < n; ++i) {
        cerr << left[i] << " " << right[i] << endl;
    }
    cerr << endl;
  */  
    int q; cin >> q;
    vector<Query> qs;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r; --l; --r;
        qs.push_back(Query{l, r, i});
    }

    sort(qs.begin(), qs.end(), [](Query a, Query b) {
        return make_pair(a.l / kMagic, a.r) < make_pair(b.l / kMagic, b.r);
    });

    int l = 0, r = -1;
    long long acc = 0;
    vector<long long> ans(q);

    for (auto q : qs) {
        while (l < q.l) { acc -= min(r + 1, right[l]) - l; ++l; }
        while (r < q.r) { ++r; acc += r - max(l - 1, left[r]); }
        while (l > q.l) { --l; acc += min(r + 1, right[l]) - l; }
        while (r > q.r) { acc -= r - max(l - 1, left[r]); r--; }
        ans[q.i] = acc;
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}