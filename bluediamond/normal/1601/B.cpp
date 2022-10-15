#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int ll

mt19937 rng((long long) (new char));
const int N = (int) 6e5 + 7;
const int INF = (int) 1e9;
int n, a[N], b[N], best[N], par[N];
vector<int> g[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];

  for (int i = 0; i < N; i++) best[i] = -1;

  /// (2 * i, 2 * i + 1)

  for (int i = 1; i <= n; i++) {
    /// from i I go to i - a[i]
    ///g[2 * i].push_back(2 * (i - a[i]) + 1);
  }


  for (int i = 1; i <= n; i++) {
    /// from i I go to i + b[i]
    g[2 * i + 1].push_back(2 * (i + b[i]));
  }

  set<int> tot;
  for (int i = 0; i <= n; i++) {
    tot.insert(2 * i + 1);
  }

  queue<int> q;
  best[2 * n] = 0;
  q.push(2 * n);



  while (!q.empty()) {
    int vertex = q.front();

    ///cout << " = " << a / 2 << " " << a % 2 << "\n";
    q.pop();
    if (vertex % 2 == 0) {
      int i = vertex / 2;
      int mn = 2 * (i - a[i]) + 1;
      int mx = 2 * i + 1;
      while (1) {
        auto it = tot.lower_bound(mn);
        if (it == tot.end()) break;
        if (*it > mx) break;
        int b = *it;
        tot.erase(it);
        assert(mn <= b && b <= mx && best[b] == -1);
        best[b] = 1 + best[vertex];
        q.push(b);
        par[b] = vertex;
      }
    } else {
      for (auto &b : g[vertex]) {
        if (best[b] == -1) {
          best[b] = 1 + best[vertex];
          q.push(b);
          par[b] = vertex;
        }
      }
    }
  }
  if (best[1] == -1) {
    cout << "-1\n";
    return 0;
  }
  cout << (best[1] + 1) / 2 << "\n";
  vector<int> path;
  int cur = 1;
  while (cur != 2 * n) {
    path.push_back(cur);
    cur = par[cur];
  }
  reverse(path.begin(), path.end());
  for (auto &x : path) {
    if (x % 2) {
      cout << x / 2 << " ";
    }
   /// cout << x % 2 << " ";
  }
  cout << "\n";
  return 0;
}
/**



**/