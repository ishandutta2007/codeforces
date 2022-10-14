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
    int n;
    cin >> n;
    vector<int> cnt(30);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 30; j++)
        if (x & (1 << j))
          cnt[j]++;
    }
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      if (!ans)
        ans = cnt[i];
      else if (cnt[i])
        ans = __gcd(ans, cnt[i]);
    }
    for (int i = 1; i <= n; i++)
      if (ans % i == 0)
        cout << i << ' ';
    cout << endl;
  }
}