#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 101010
#define rem ((llong)1e9+7)

string s, p;

int kmp[maxn];
bool pos[maxn] = {0};
llong dp[maxn] = {0}, sum[maxn] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> s >> p;
  rep1(i, len(p) - 1) {
    int& f = kmp[i]; f = kmp[i - 1];
    while (f and p[f] != p[i]) f = kmp[f - 1];
    if (p[f] == p[i]) ++f;
  }
  
  int ml = 0;
  rep(i, len(s)) {
    while (ml and p[ml] != s[i]) ml = kmp[ml - 1];
    if (p[ml] == s[i]) ++ml;
    if (ml != len(p)) continue;
    pos[i] = 1;
    ml = kmp[ml - 1];
    // clog << i - len(p) + 1 << endl;
  }
  
  int last = -1;
  rep(i, len(s)) {
    if (pos[i]) last = i - len(p) + 1;
    if (i) dp[i] = dp[i - 1];
    if (last != -1) {
      llong t = (last > 0 ? sum[last - 1] : 0) + last + 1;
      (dp[i] += t) %= rem;
    }
    if (i) sum[i] = sum[i - 1];
    (sum[i] += dp[i]) %= rem;
  }
  
  cout << dp[len(s) - 1];
  
  return 0;
}