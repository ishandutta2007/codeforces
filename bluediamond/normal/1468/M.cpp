#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int R = 333;
int n;
int f[N];
int idol;
vector<int> a[N];
bool big[N];
vector<int> where[N];

pair<int, int> solve() {

  for (int i = 1; i <= n; i++) {
    if (big[i]) {
      for (auto &x : a[i]) f[x]++;
      for (int j = 1; j <= n; j++) {
        if (i != j) {
          int cnt = 0;
          for (auto &x : a[j]) {
            cnt += (f[x] == 1);
            f[x]++;
          }
          for (auto &x : a[j]) {
            f[x]--;
          }
          if (cnt >= 2) {
            for (auto &x : a[i]) f[x]--;
            return {i, j};
          }
        }
      }
      for (auto &x : a[i]) f[x]--;
    }
  }
  /// we only care about small-small from now on:)
  for (int i = 1; i <= n; i++) {
    if (!big[i]) {
      for (auto &x : a[i]) {
        where[x].push_back(i);
      }
    }
  }
  for (int x = idol; x >= 1; x--) {
    /// where[x]
    for (auto &i : where[x]) {
      a[i].pop_back();
    }
    int ind = -1, sol = -1;
    for (auto &i : where[x]) {
      for (auto &val : a[i]) {
        if (f[val]) {
          ind = i;
          sol = val;
          break;
        }
        f[val]++;
      }
      if (ind != -1) {
        break;
      }
    }
    if (ind != -1) {
      for (auto &i : where[x]) {
        for (auto &val : a[i]) {
          if (val == sol) {
            return {i, ind};
          }
        }
      }
    }
    for (auto &i : where[x]) {
      for (auto &val : a[i]) f[val]--;
    }
  }
  return {-1, -1};
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 // freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    map<int, int> tr;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      int l;
      cin >> l;
      a[i].resize(l);
      for (auto &x : a[i]) {
        cin >> x;
        tr[x] = 0;
      }
      sort(a[i].begin(), a[i].end());
      big[i] = (l >= R);
    }
    idol = 0;
    for (auto &it : tr) {
      it.second = ++idol;
      where[idol].clear();
      f[idol] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (auto &x : a[i]) {
        x = tr[x];
      }
    }
    auto it = solve();
    if (it.first == -1) {
      cout << "-1\n";
    } else {
      cout << it.first << " " << it.second << "\n";
    }
  }

}