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
  // int n;
  // cin >> n;
  // vector<int> r(n);
  // iota(all(r), 1);
  // do {
  //   bool z = 1;
  //   for (int i = 0; i < n - 1; i++)
  //     z = z && (r[i] <= r[i + 1] + 1);
  //   if (z) {
  //     // for (int i = 0; i < n; i++)
  //     // cout << r[i] << " \n"[i == n - 1];
  //     for (int i = 1; i < n; i++)
  //       cout << r[i] - r[i - 1] << " \n"[i == n - 1];
  //   }
  // } while (next_permutation(all(r)));
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll k;
    cin >> n >> k;
    if (n <= 61 && (1ull << (n - 1)) < k) {
      cout << -1 << endl;
      continue;
    }
    k--;
    queue<int> id;
    for (int i = 0; i < min(61, n) - 1; i++)
      id.push(!!(k & (1ull << i)));
    while (id.size() != n)
      id.push(0);
    vector<int> ans;
    int h = n;
    while (id.size()) {
      int cnt = 1;
      while (id.front() == 1)
        cnt++, id.pop();
      id.pop();
      for (int i = h - cnt + 1; i <= h; i++)
        ans.pb(i);
      h -= cnt;
    }
    reverse(all(ans));
    for (int i : ans)
      cout << i << ' ';
    cout << endl;
  }
}