#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    string s, t; cin >> s >> t;
    vector<int> cnt(26, 0);
    for (int i = 0; i < (int)s.size(); ++i)
      cnt[s[i] - 'a'] += 1;
    vector<int> perm(26);
    for (int i = 0; i < 26; ++i)
      perm[i] = i;

    if (t == "abc" && cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) 
      swap(perm[1], perm[2]);

    for (auto i : perm) 
      for (int j = 0; j < cnt[i]; ++j)
        cout << char(i + 'a');
    cout << '\n';
  }
}