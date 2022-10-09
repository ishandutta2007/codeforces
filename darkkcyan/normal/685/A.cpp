#include <bits/stdc++.h>
using namespace std;

#define llong long long 
int n, m;

string to7(int num) {
  if (num == 0) return "0";
  string ans = "";
  for (; num > 0; num /= 7) 
    ans += char('0' + num % 7);
  reverse(ans.begin(), ans.end());
  return ans;
}

struct dpcal {
  llong dp[30][1 << 7][2];
  string s;
  dpcal() {}
  dpcal(const string& _s): s(_s) {
    //clog << s << endl;
    memset(dp, -1, sizeof(dp));
  }
  llong cal(int p, int mask, bool smaller) {
    if (p == (int)s.size()) return mask == 0;
    if (dp[p][mask][smaller] != -1) return dp[p][mask][smaller];
    dp[p][mask][smaller] = 0;
    int md = smaller ? s[p] - '0' : 6;
    for (int i = 0; i <= md; ++i) {
      bool ns = i == md and smaller;
      if ((~mask >> i) & 1) continue;
      dp[p][mask][smaller] += cal(p + 1, mask & ~(1 << i), ns);
    }
    return dp[p][mask][smaller];
  }
};

dpcal d1, d2;

int main() {
  cin >> n >> m;
  d1 = dpcal(to7(n - 1));
  d2 = dpcal(to7(m - 1));
  llong ans = 0;
  for (int i = 0; i < (1 << 7); ++i)
    for (int f = 0; f < (1 << 7); ++f) {
      if (i & f) continue;
      ans += d1.cal(0, i, 1) * d2.cal(0, f, 1);
    }
  cout << ans;
  return 0;
}