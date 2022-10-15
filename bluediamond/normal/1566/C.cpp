/**

48 -> 8:17
43 -> 8:33
42 -> 8:42
41 -> 8:47

**/

#include <bits/stdc++.h>

using namespace std;


int gain(set<int> s) {
  int mex = 0;
  while (s.count(mex)) {
    mex++;
  }
  return mex;
}

int tt, n;
string s, t;


int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> tt;
  while (tt--) {
    cin >> n >> s >> t;
    vector<vector<int>> v(n, vector<int> (2));
    for (int i = 0; i < n; i++) {
      v[i][0] = s[i] - '0';
      v[i][1] = t[i] - '0';
    }
    vector<set<int>> stk;
    stk.push_back({});
    for (auto &x : v[0]) stk.back().insert(x);
    for (int i = 1; i < n; i++) {
      set<int> s1 = stk.back();
      for (auto &x : v[i]) s1.insert(x);

      set<int> s2a = stk.back(), s2b;
      for (auto &x : v[i]) s2b.insert(x);
      if (gain(s1) > gain(s2a) + gain(s2b)) {
        stk.back() = s1;
      } else {
        stk.push_back(s2b);
      }
    }
    int sol = 0;
    for (auto &st : stk) {
      sol += gain(st);
    }
    cout << sol << "\n";
  }
  return 0;
}