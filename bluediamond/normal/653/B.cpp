#include <bits/stdc++.h>

using namespace std;

set<string> ok;
vector<pair<string, string>> ops;
int len, sol, op;

void dfs(string s) {
  if ((int) s.size() == len) {
    sol++;
    return;
  }
  for (auto &it : ops) {
    if (it.second[0] == s[0]) {
      string t;
      t = it.first;
      for (int i = 1; i < (int) s.size(); i++) {
        t += s[i];
      }
      if (ok.count(t) == 0) {
        dfs(t);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> len >> op;
  for (int i = 0; i < op; i++) {
    string a, b;
    cin >> a >> b;
    ops.push_back({a, b});
  }
  ok.insert("a");
  dfs("a");
  cout << sol << "\n";

}