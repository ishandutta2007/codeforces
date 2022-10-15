#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 7;
int n, a[N];
multiset<int> s;
vector<pair<int, int>> ret;

void algo(int x) {
  if (s.empty()) {
    return;
  }
  auto it = s.end();
  it--;
  int fi = *it, sc = x - fi;
  ret.push_back({fi, sc});
  s.erase(s.find(fi));
  if (s.count(sc)) {
    s.erase(s.find(sc));
    algo(fi);
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    bool ok = 0;
    for (int i = 1; i < n; i++) {
      s.clear();
      for (int j = 1; j <= n; j++) {
        s.insert(a[j]);
      }
      ret.clear();
      algo(a[i] + a[n]);
      if (s.empty()) {
        ok = 1;
        cout << "YES\n";
        cout << a[i] + a[n] << "\n";
        for (auto &it : ret) {
          cout << it.first << " " << it.second << "\n";
        }
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
  }
}
/// 1 2 3 3 4 5 6 7 11 14