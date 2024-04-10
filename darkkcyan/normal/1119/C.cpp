#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

int n, m;
vector<vector<bool>> a, b;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n, vector<bool>(m));
    b = a;
    rep(i, n) rep(f, m) {
      int u; cin >> u; a[i][f] = !!u;
    }
    rep(i, n) rep(f, m) {
      int u; cin >> u; b[i][f] = !!u;
    }

    rep(i, n - 1) rep(f, m - 1)
      if (a[i][f] != b[i][f]) {
        rep(g, 4) a[i + (g & 1)][f + (g >> 1)] = !a[i + (g & 1)][f + (g >> 1)];
      }
    cout << ((a == b) ? "YES" : "NO");

    return 0;
}