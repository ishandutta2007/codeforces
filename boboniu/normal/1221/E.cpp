#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    s = s + "X";
    int n = s.size();
    vector<int> piece;
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '.') {
        p++;
      } else {
        if (s[i] == 'X') {
          if (p != 0) {
            piece.push_back(p);
          }
          p = 0;
        }
      }
    }
    int type2 = 0, type3 = 0, type4 = 0;
    int c4 = 0;
    for (auto p : piece) {
      if (p < b) continue;
      if (p >= b && p < a) {
        type2++;
      } else if (p >= a && p < 2 * b) {
        type3++;
      } else {
        type4++;
        c4 = p;
      }
    }
    auto check=[&]() {
      if (type2 >= 1) return false;
      if (type4 >= 2) return false;
      if (type4 == 0) return type3 % 2 == 1;
      c4 -= a;
      for (int l = 0; l <= c4; l++) {
        int r = c4 - l;
        if (l >= b && l < a) continue;
        if (r >= b && r < a) continue;
        if (l >= 2 * b) continue;
        if (r >= 2 * b) continue;
        int ntype3 = type3;
        if (l >= a && l < 2 * b) ntype3++;
        if (r >= a && r < 2 * b) ntype3++;
        if (ntype3 % 2 == 0) return true;
      }
      return false;
    };
    if (check() == 0) {
      cout << "No" << "\n";
    } else {
      cout << "Yes" << "\n";
    }
  }
  return 0;
}