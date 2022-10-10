#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back

ve<ve<ii> > gr;
int m, n, k;
set<int> bk;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i, f, g;

    cin >> n >> m >> k;
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        gr[a].pb(ii(b, c));
        gr[b].pb(ii(a, c));
    }

    for (int i = 0; i < k; ++i) {
        int b; cin >> b; --b;
        bk.insert(b);
    }

    int ans = INT_MAX;

    set<int>::iterator it;
    for (it = bk.begin(); it != bk.end(); ++it) {
        for (int i = 0; i < sz(gr[*it]); ++i) {
            int v = gr[*it][i].first;
            int c = gr[*it][i].second;
            if (bk.count(v) > 0) continue;
            ans = min(ans, c);
        }
    }

    if (ans == INT_MAX) ans = -1;
    cout << ans;

    return 0;
}