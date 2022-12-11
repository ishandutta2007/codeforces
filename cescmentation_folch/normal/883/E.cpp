#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> disc(26, false);
  for (int j = 0; j < n; ++j) {
    if (s[j] != '*') disc[s[j] - 'a'] = true;
  }
  int m;
  cin >> m;
  vector<int> quantes(26, 0);
  int bones = 0;
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t;
    bool bona = true;
    for (int j = 0; j < n; ++j) {
      if (s[j] != '*' and s[j] != t[j]) bona = false;
      if (s[j] == '*' and disc[t[j] - 'a']) {
        bona = false;
      }
    }
    if (bona) {
      ++bones;
      vector<bool> ap(26, false);
      for (int j = 0; j < n; ++j) if (s[j] == '*') ap[t[j] - 'a'] = true;
      for (int c = 0; c < 26; ++c) if (ap[c]) quantes[c]++;
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) if (quantes[i] == bones) ++ans;
  cout << ans << endl;
}