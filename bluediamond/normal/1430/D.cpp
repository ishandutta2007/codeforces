#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;
vector<int> a;

bool ok(int cnt) {
  /// dispar primele cnt
  int get = 0;
  for (int i = 0; i < cnt; i++) {
    get += a[i] - 1;
    get = min(get, i + 1);
  }
  for (int i = cnt; i < n; i++) {
    get += a[i];
  }
  return get >= cnt - 1;
}

int solve(vector<int> aaa) {
  a = aaa;
  n = (int) a.size();
  int sol = 0, l = 1, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      sol = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> l;
    l.push_back(1);
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1]) {
        l.back()++;
      } else {
        l.push_back(1);
      }
    }
    cout << solve(l) << "\n";
  }

}