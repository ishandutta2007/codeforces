/// 506 -> 507
#include <bits/stdc++.h>

using namespace std;



int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int offs, len;
    cin >> offs >> len;
    vector<int> cnt(len, 0);
    for (int i = 0; i < offs; i++) {
      int l;
      cin >> l;
      l--;
      l = min(l, len - 1 - l);
      cnt[l]++;
    }
    string s(len, 'B');
    assert((int) s.size() == len);
    for (int i = 0; i < len; i++) {
      if (cnt[i] >= 1) s[i] = 'A';
      if (cnt[i] >= 2) s[len - 1 - i] = 'A';
    }
    cout << s << "\n";
  }

}