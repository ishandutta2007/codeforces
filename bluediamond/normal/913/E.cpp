#include <bits/stdc++.h>

using namespace std;

struct dijState {
  string s;
  int mask;
  int j;
};

bool operator < (dijState a, dijState b) {
  return make_pair((int) a.s.size(), a.s) > make_pair((int) b.s.size(), b.s);
}

bool vis[1 << 8][3];
string sol[1 << 8][3];

priority_queue<dijState> q;

int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  q.push({"x", 240, 2}); /// 16 + 32 + 64 + 128
  q.push({"y", 204, 2}); /// 4 + 8 + 64 + 128
  q.push({"z", 170, 2}); /// 2 + 8 + 32 + 128

  while (!q.empty()) {
    auto it = q.top();
    q.pop();
    if (vis[it.mask][it.j]) {
      continue;
    }
    vis[it.mask][it.j] = 1;
    sol[it.mask][it.j] = it.s;
    if (it.j == 2) {
      /// full expression
      /// X
      q.push({it.s, it.mask, 1});
      q.push({"!" + it.s, 255 ^ it.mask, 2});
      for (int m2 = 0; m2 < 255; m2++) {
        if (vis[m2][2]) {
          q.push({it.s + "&" + sol[m2][2], m2 & it.mask, 1});
          q.push({sol[m2][2] + "&" + it.s, m2 & it.mask, 1});
        }
      }
    }
    if (it.j == 1) {
      /// X and Y and Z
      q.push({it.s, it.mask, 0});
      for (int m2 = 0; m2 < 255; m2++) {
        if (vis[m2][2]) {
          q.push({it.s + "&" + sol[m2][2], m2 & it.mask, 1});
          q.push({sol[m2][2] + "&" + it.s, m2 & it.mask, 1});
        }
        if (vis[m2][1]) {
          q.push({it.s + "&" + sol[m2][1], m2 & it.mask, 1});
          q.push({sol[m2][1] + "&" + it.s, m2 & it.mask, 1});
        }
        if (vis[m2][0]) {
          q.push({it.s + "|" + sol[m2][0], m2 | it.mask, 0});
          q.push({sol[m2][0] + "|" + it.s, m2 | it.mask, 0});
        }
      }
    }
    if (it.j == 0) {
      /// X or Y or Z
      q.push({"(" + it.s + ")", it.mask, 2});
      for (int m2 = 0; m2 < 255; m2++) {
        if (vis[m2][0]) {
          q.push({it.s + "|" + sol[m2][0], m2 | it.mask, 0});
          q.push({sol[m2][0] + "|" + it.s, m2 | it.mask, 0});
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int mask = 0;
    for (int j = 0; j < 8; j++) {
      if (s[j] == '1') {
        mask += (1 << j);
      }
    }
    string ans = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
    for (int j = 0; j < 3; j++) {
      if (vis[mask][j]) {
        if (make_pair((int) sol[mask][j].size(), sol[mask][j]) < make_pair((int) ans.size(), ans)) {
          ans = sol[mask][j];
        }
      }
    }
    cout << ans << "\n";
  }
}