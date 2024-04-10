#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 200000 + 7;
int n;
int w;
pair<int, int> a[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    vector<int> take;
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      if (sol + a[i].first <= w) {
        sol += a[i].first;
        take.push_back(a[i].second);
      } else {
        break;
      }
    }
    if (sol * 2 >= w) {
      sort(take.begin(), take.end());
      cout << (int) take.size() << "\n";
      for (auto &i : take) {
        cout << i << " ";
      }
      cout << "\n";
      continue;
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
      if (2 * a[i].first >= w && a[i].first <= w) {
        ok = 1;
        cout << "1\n";
        cout << a[i].second << "\n";
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
      continue;
    }
  }


}