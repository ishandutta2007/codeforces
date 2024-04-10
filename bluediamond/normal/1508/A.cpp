#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

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

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    string s[3], ret;
    vector<int> p(3, 0);
    int n;
    cin >> n >> s[0] >> s[1] >> s[2];
    while (max({p[0], p[1], p[2]}) < 2 * n) {
      vector<int> need(2, 0);
      for (int i = 0; i <= 2; i++) {
        need[s[i][p[i]] - '0']++;
      }
      if (need[0] >= need[1]) {
        ret += '0';
        for (int i = 0; i <= 2; i++) {
          if (s[i][p[i]] == '0') {
            p[i]++;
          }
        }
      } else {
        ret += '1';
        for (int i = 0; i <= 2; i++) {
          if (s[i][p[i]] == '1') {
            p[i]++;
          }
        }
      }
    }
    if (p[2] == 2 * n) {
      swap(p[2], p[0]);
      swap(s[2], s[0]);
    }
    if (p[1] == 2 * n) {
      swap(p[1], p[0]);
      swap(s[1], s[0]);
    }
    if (p[2] >= p[1]) {
      swap(p[1], p[2]);
      swap(s[1], s[2]);
    }
    while (p[1] < 2 * n) {
      ret += s[1][p[1]];
      p[1]++;
    }
    cout << ret << "\n";
  }
  return 0;
}