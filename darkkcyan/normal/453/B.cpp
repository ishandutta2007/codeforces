#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 111
#define maxb 17
#define maxa 30
#define inf 10101010
int pmask[maxn] = {0};
void genprime() {
  int curp = 0;
  for (int i = 1; ++i < maxn; ) {
    if (pmask[i]) continue;
    for (int f = i; f < maxn; f += i)
      pmask[f] |= (1ll << curp);
    ++curp;
  }
  rep(i, maxn) pmask[i] &= (1 << maxb) - 1;
}

int dp[maxn][1 << maxb];
int tr[maxn][1 << maxb];

int n;
int a[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  rep1(i, n) cin >> a[i];
  rep(i, (1 << maxb)) dp[0][i] = inf;
  dp[0][0] = 0;
  tr[0][0] = -1;
  
  genprime();
  // rep(i, maxn) clog << i << ' ' << bitset<maxb>(pmask[i]) << endl;
  
  // clog << "input ok" << endl;
  rep1(i, n) {
    // clog << i << endl;
    rep(f, (1 << maxb)) dp[i][f] = dp[i - 1][f] + abs(a[i] - 1), tr[i][f] = 1;
    for (int f = 2; f <= 60; ++f) {
      int s = (~pmask[f]) & ((1ll << maxb) - 1);
      for (int t = s; ; t = (t - 1) & s) {
        // clog <<bitset<maxb>(t) << endl;
        int x = dp[i - 1][t] + abs(f - a[i]);
        if (x < dp[i][t | pmask[f]]) {
          dp[i][t | pmask[f]] = x;
          tr[i][t | pmask[f]] = f;
        }
        if (t == 0) break;
      }
    }
  }
  
  // clog << "process ok" << endl;
  
  int ans = 0;
  rep(i, (1 << maxb)) {
    if (dp[n][ans] > dp[n][i]) ans = i;
  }
  
  vector<int> b(n);
  for (int i = n; i > 0; --i) {
    b[i - 1] = tr[i][ans];
    ans &= ~pmask[tr[i][ans]];
  }
  
  for (auto i: b) cout << i << ' ';
  
  return 0;
}