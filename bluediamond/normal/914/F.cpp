#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;
string s;
int len;
int q;
bitset<N> pos[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> q;
  len = (int) s.size();
  for (int i = 0; i < len; i++) {
    pos[s[i] - 'a'][i] = 1;
  }
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      string t;
      cin >> i >> t;
      i--;
      if (s[i] != t[0]) {
        pos[s[i] - 'a'][i] = 0;
        pos[t[0] - 'a'][i] = 1;
        s[i] = t[0];
      }
    } else {
      int l, r, sz;
      string t;
      cin >> l >> r >> t;
      sz = (int) t.size();
      l--;
      r--;
      r = r - sz + 1;
      if (l > r) {
        cout << "0\n";
        continue;
      }
      bitset<N> good;
      good.reset();
      good = ~good;
      for (int i = 0; i < sz; i++) {
        good &= (pos[t[i] - 'a'] >> i);
      }
      int ans = 0;
      good >>= l;
      ans = good.count();
      good >>= (r - l + 1);
      ans -= good.count();
      cout << ans << "\n";
    }
  }
}