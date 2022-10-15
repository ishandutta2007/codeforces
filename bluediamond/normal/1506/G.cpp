#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

set<char> are;
map<char, int> last, first;
string s, sol;

void put() {
  last.clear();
  first.clear();
  are.clear();
  for (auto &x : s) are.insert(x);
  for (int i = 0; i < (int) s.size(); i++) last[s[i]] = i + 1;
  for (int i = (int) s.size() - 1; i >= 0; i--) first[s[i]] = i + 1;
}

void del(char ch) {
  string t;
  int p = 0;
  while (s[p] != ch) p++;
  bool found = 0;
  for (int j = 0; j < (int) s.size(); j++) {
    found |= (s[j] == ch);
    if (s[j] == ch) continue;
    if (!found) continue;
    t += s[j];
  }
  assert((int) t.size() < (int) s.size());
  s = t;
  put();
}

signed realMain() {
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> s;
    put();
    sol.clear();
    while (!s.empty()) {
      int min_last = (int) 1e9;
      for (auto &x : last) {
        min_last = min(min_last, x.second);
      }
      vector<char> inv;
      for (auto &x : are) inv.push_back(x);
      reverse(inv.begin(), inv.end());
      for (auto &x : inv) {
        if (first[x] <= min_last) {
          del(x);
          sol += x;
          break;
        }
      }
     /// cout << s << " : " << sol << "\n";
    }
    cout << sol << "\n";
  }
  return 0;
}