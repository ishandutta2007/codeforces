#include <bits/stdc++.h>

bool home = 1;
using namespace std;

typedef long long ll;


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    vector<int> fs(26, 0), ft(26, 0);
    for (auto &ch : s) fs[ch - 'A']++;
    for (auto &ch : t) ft[ch - 'A']++;

    bool ok = true;
    for (int i = 0; i < 26; i++) {
      ok &= (fs[i] >= ft[i]);
      ft[i] = fs[i] - ft[i];
    }

    if (!ok) {
      cout << "NO\n";
      continue;
    }
    string gen;
    for (auto &ch : s) {
      int x = ch - 'A';
      if (ft[x]) {
        ft[x]--;
        continue;
      }
      gen += ch;
    }

    cout << ((gen == t) ? "YES" : "NO") << "\n";
  }

}