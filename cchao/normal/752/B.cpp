#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
int v[128];
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  REP(i, n) {
    if (v[a[i]] || v[b[i]]) {
      if (v[a[i]] != b[i] || v[b[i]] != a[i]) {
        puts("-1");
        return 0;
      }
    }
    v[a[i]] = b[i];
    v[b[i]] = a[i];
  }
  vector<pair<char, char>> ans;
  REP(i, 128) if (v[i] && i < v[i]) {
    ans.emplace_back(i, v[i]);
  }
  cout << ans.size() << endl;
  for (auto it : ans)
    cout << it.first << ' ' << it.second << endl;
  return 0;
}