#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int a, b, ab, ba;
    string s;
    cin >> a >> b >> ab >> ba >> s;
    int cnt_a = 0;
    int cnt_b = 0;
    vector<int> v((int) s.size());
    for (int i = 0; i < (int) v.size(); i++) {
      v[i] = s[i] - 'A';
      cnt_a += (v[i] == 0);
      cnt_b += (v[i] == 1);
    }
    if (cnt_a != a + ab + ba || cnt_b != b + ab + ba) {
      cout << "NO\n";
      continue;
    }
    vector<int> need(2, 0), have(2, 0);
    vector<vector<vector<int>>> all(2, vector<vector<int>> (2));
    need[0] = ab;
    need[1] = ba;
    int l = 0;
    while (l < (int) v.size()) {
      int r = l;
      while (r + 1 < (int) v.size() && v[r] != v[r + 1]) {
        r++;
      }
      all[v[l]][v[r]].push_back(r - l + 1);
      l = r + 1;
    }
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        for (auto &l : all[x][y]) {
          have[x] += l / 2;
        }
      }
    }
    if (have[0] >= need[0] && have[1] >= need[1]) {
      cout << "YES\n";
      continue;
    }
    if (have[1] < need[1]) {
      swap(have[0], have[1]);
      swap(need[0], need[1]);
      for (auto &x : v) {
        x ^= 1;
      }
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          all[x][y].clear();
        }
      }
      l = 0;
      while (l < (int) v.size()) {
        int r = l;
        while (r + 1 < (int) v.size() && v[r] != v[r + 1]) {
          r++;
        }
        all[v[l]][v[r]].push_back(r - l + 1);
        l = r + 1;
      }
    }
    int want0 = need[0] - have[0], can_kill1 = have[1] - need[1];
    {
      vector<int> toate;
      for (int y = 0; y < 2; y++) {
        sort(all[1][y].begin(), all[1][y].end());
        reverse(all[1][y].begin(), all[1][y].end());
        for (auto &l : all[1][y]) {
          toate.push_back(l);
        }
      }
      sort(toate.begin(), toate.end());
      reverse(toate.begin(), toate.end());
      for (int y = 1; y >= 0; y--)
      for (auto &l : all[1][y]) {
        if (l / 2 <= can_kill1) {
          want0 = max(0, want0 - (l - 1) / 2);
          can_kill1 -= l / 2;
          continue;
        }
        int Get = (2 * can_kill1 + (l % 2 == 1) - 1) / 2;
        want0 = max(0, want0 - Get);
        can_kill1 = 0;
      }
    }
    if (want0 == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}