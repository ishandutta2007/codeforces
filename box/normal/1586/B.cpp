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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      s.insert(b);
    }
    int i = 1;
    while (s.count(i))
      i++;
    for (int j = 1; j <= n; j++)
      if (j != i)
        cout << i << ' ' << j << endl;
  }
}