#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int no[1000006];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> g(n);
  for (int i = 0; i < n; i++)
    cin >> g[i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < m - 1; j++)
      if (g[i][j] == 'X' && g[i - 1][j + 1] == 'X')
        no[j + 1] = 1;
  for (int j = 1; j <= m; j++)
    no[j] += no[j - 1];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << (no[r - 1] != no[l - 1] ? "NO" : "YES") << endl;
  }
}