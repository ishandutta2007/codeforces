#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; ++i <= n; )
#define len(s) ((int)s.size())

string s, t;
llong cnts[128] = {0};
llong cntt[128] = {0};

bool ok(int orr) {
  llong c[128];
  memset(c, 0, sizeof(c));
  for (int i = 'a'; i <= 'z'; ++i) {
    c[i] = orr * cntt[i] - cnts[i];
  }
  llong s = 0;
  rep(i, 128) s += c[i] > 0 ? c[i] : 0;
  return (cnts['?'] >= s);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s >> t;
  for (auto i: s) cnts[(int)i]++;
  for (auto i: t) cntt[(int)i]++;

  int l = 0, r = len(s) / len(t) + 10;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (ok(mid)) l = mid;
    else r = mid - 1;
  }
  
  for (int i = 'a'; i <= 'z'; ++i) (cntt[i] *= l) -= cnts[i];
  int f = 'a';
  for (auto i: s) {
    if (i != '?') cout << i;
    else {
      while (f <= 'z' and cntt[f] <= 0) ++f;
      if (f > 'z') cout << 'a';
      else cout << (char)f;
      --cntt[f];
    }
  }

  return 0;
}