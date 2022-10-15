#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

void simp(int &a, int &b) {
  int g = __gcd(a, b);
  a /= g;
  b /= g;
}

bool prod(int a, int b, int c, int d) {
  simp(a, c);
  simp(a, d);
  simp(b, c);
  simp(b, d);
  return (a == 1 && b == 1 && c == 1 && d == 1);
}

int n, a, b, c, sol = 0;
map<pair<int, int>, int> mp;
set<int> s1, s2;

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c;
    sol = __gcd(sol, c);
    s1.insert(a);
    s2.insert(b);
    mp[{a, b}] = c;
  }
  if ((int) s1.size() * (int) s2.size() != n) {
    cout << "0\n";
    return 0;
  }
  vector<vector<int>> v;
  for (auto &x : s1) {
    vector<int> now;
    for (auto &y : s2) {
      now.push_back(mp[{x, y}]);
    }
    v.push_back(now);
  }
  for (int i = 0; i < (int) s1.size() - 1; i++) {
    for (int j = 0; j < (int) s2.size() - 1; j++) {
      int a = v[i][j], b = v[i][j + 1], c = v[i + 1][j], d = v[i + 1][j + 1];
      /// a/b = c/d
      if (!prod(a, d, b, c)) {
        cout << "0\n";
        return 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i * i <= sol; i++) {
    if (sol % i == 0) {
      cnt += 2;
      if (i * i == sol) {
        cnt--;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}