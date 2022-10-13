#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    string stk;
    for (int i = 0; i < n; ++i) {
      if (stk.empty() || s[i] == 'A')
        stk.push_back(i);
      else stk.pop_back();
    }
    cout << stk.size() << '\n';
  }

  return 0;
}