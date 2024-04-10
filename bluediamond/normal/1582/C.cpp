#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
#define int ll

const int INF = (int) 1e9;
int n;
int sol;
string s;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    cin >> s;
    //n = (int) s.size();
    sol = INF;

    for (char spec = 'a'; spec <= 'z'; spec++) {
      string without;
      for (auto &x : s) {
        if (x == spec) continue;
        without += x;
      }
      string inv = without;
      reverse(inv.begin(), inv.end());
      if (inv != without) continue;

      vector<int> pos;
      pos.push_back(-1);
      for (int i = 0; i < n; i++) {
        if (s[i] != spec) pos.push_back(i);
      }
      pos.push_back(n);
      int y = (int) pos.size();
      int del = n - (int) without.size();

      for (int j = 0; j < (y - 1) / 2; j++) {
        int l1 = pos[j] + 1, r1 = pos[j + 1] - 1;
        int l2 = pos[y - 1 - j - 1] + 1, r2 = pos[y - 1 - j] - 1;
        int c1 = 0, c2 = 0;
        for (int j = l1; j <= r1; j++) c1 += (s[j] == spec);
        for (int j = l2; j <= r2; j++) c2 += (s[j] == spec);
        del -= 2 * min(c1, c2);
      }
      if (y % 2 == 0) {
        int l = pos[y / 2 - 1] + 1, r = pos[y / 2] - 1;
        int cnt = 0;
        for (int j = l; j <= r; j++) cnt += (s[j] == spec);
        del -= cnt;
      }
      if (spec == 'z') {
       // cout << " : " << del << "\n";
      }
      sol = min(sol, del);
    }
    if (sol == INF) sol = -1;
    cout << sol << "\n";
  }

  return 0;
}
/**



**/