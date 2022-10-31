%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
 
const int N = 100005;
const ll mod = 1e9 + 7;
 
ll mod1, mod2, mod3;
ll bas1, bas3, bas2;
string s, t;
int n, m;
 
int solve() {
  int res = 0;
  int mn = min(n, m);
  ll hs1 = 0, hs2 = 0, hs3 = 0;
  ll ht1 = 0, ht2 = 0, ht3 = 0;
  ll p1 = 1, p2 = 1, p3 = 1;
  for (int i = 0; i < mn; i++) {
    hs1 = (hs1 + p1 * s[n - 1 - i]) % mod1;
    hs2 = (hs2 + p2 * s[n - 1 - i]) % mod2;
    hs3 = (hs3 + p3 * s[n - 1 - i]) % mod3;
    ht1 = (ht1 * bas1 + t[i]) % mod1;
    ht2 = (ht2 * bas2 + t[i]) % mod2;
    ht3 = (ht3 * bas3 + t[i]) % mod3;
    p1 = (p1 * bas1) % mod1;
    p2 = (p2 * bas2) % mod2;
    p3 = (p3 * bas3) % mod3;
    if (hs1 == ht1 && hs2 == ht2 && hs3 == ht3) 
      res = max(res, i + 1);
  }
  return res;
}
 
int q;
 
int main() {
  //ios :: sync_with_stdio(false); cin.tie(0);
  cin >> q;
  bas1 = 131, bas2 = 13131, bas3 = 9283;
  mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 19260817;
 
  for (int i = 0; i < q; i++) {
    cin >> t;
    //cout << i << ": " << t << '\n';
    if (i == 0) {
      s = t;
    }
    else {
      n = s.size(), m = t.size();
      int tmp = solve();
      //printf("%d -> %d\n", i, tmp);
      for (int i = tmp; i < m; i++)
        s += t[i];
    }
    //printf("%d\n", i);
  }
  cout << s << '\n';
  return 0;
}