#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


int f(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  int cnt_1 = 0, sz = (int) s.size();
  for (auto &ch : s) {
    cnt_1 += (ch == '1');
  }
  if (s != t) {
    if (sz % 2 == 1) {
      if (cnt_1 == sz - 2) {
        if (s[sz / 2] == '0') return 0;
        return -1;
      }
    }
    if (cnt_1 % 2 == 1) return -1;
    return -1;
  }
  if (cnt_1 == sz) return 0;
  if (sz % 2 == 0) return +1;

  if (s[sz / 2] == '1') return +1;

  if (cnt_1 == (int) sz - 1) return 1;
  return -1;
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int x = f(s);
    if (x == 0) cout << "DRAW\n";
    if (x == +1) cout << "BOB\n";
    if (x == -1) cout << "ALICE\n";
  }
  return 0;
}