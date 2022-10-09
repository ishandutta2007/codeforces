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
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Sol {

#define maxn 1010101
bool hh[maxn] = {0};

int main() {
    int n, m, k; cin >> n >> m >> k;
    rep(i, m) {
        int t; cin >> t;
        hh[t] = 1;
    }

    int b = 1;
    if (hh[1]) cout << 1, exit(0);
    rep(i, k) {
        int u, v; cin >> u >> v;
        if (u != b and v != b) continue;
        if (u != b) swap(u, v);
        b = v;
        if (hh[b]) cout << b, exit(0);
    }
    cout << b;

    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}