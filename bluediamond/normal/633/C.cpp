#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 7;
const int L = 1000000 + 7;

int len, cnt, last, go[L][26], id[L], nn, par[N], print[N];
string s, t;
string strs[L];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> len >> s >> cnt;
  for (int i = 1; i <= cnt; i++) {
    cin >> t;
    strs[i] = t;
    reverse(t.begin(), t.end());
    int cur = 0;
    for (auto &x : t) {
      int c;
      if ('a' <= x && x <= 'z') {
        c = x - 'a';
      } else {
        c = x - 'A';
      }
      if (go[cur][c] == 0) {
        go[cur][c] = ++nn;
      }
      cur = go[cur][c];
    }
    id[cur] = i;
  }
  for (int i = 0; i <= len; i++) {
    if (i == 0 || print[i]) {
      int cur = 0;
      for (int j = i + 1; j <= len; j++) {
        int c = s[j - 1] - 'a';
        if (go[cur][c] == 0) {
          break;
        }
        cur = go[cur][c];
        if (id[cur]) {
          par[j] = i;
          print[j] = id[cur];
        }
      }
    }
  }
  vector<string> sol;
  int i = len;
  while (i) {
    sol.push_back(strs[print[i]]);
    i = par[i];
  }
  reverse(sol.begin(), sol.end());
  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
}