#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define rem ((llong)1e9+7)

#define maxn 300
#define hor 1
#define ver 2
int n, m;
int a[maxn][maxn];

inline int getsym(char* s[3]) {
  int cnt0 = 0;
  rep(i, 3) rep(f, 3) cnt0 += s[i][f] == 'O';
  if (cnt0 == 0 or cnt0 == 1 or cnt0 == 4 or cnt0 == 5) return 0;
  if (cnt0 == 2 or cnt0 == 3) return s[0][0] == 'O' ? hor : ver;
  return s[0][1] == 'O' ? hor : ver;
}

llong dp[maxn];
llong dp1[maxn][2];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep1(i, n) {
    static char s[3][maxn * 5];
    cin >> s[0];
    char *t[3];
    rep(i, 3) cin >> s[i], t[i] = s[i] + 1;
    rep1(f, m) {
      a[i][f] = getsym(t);
      rep(i, 3) t[i] += 4;
    }
  }
  // rep1(i, n) {
  //   rep1(f, m) clog << a[i][f];
  //   clog << endl;
  // }
  
  dp[0] = 1;
  rep1(i, m) {
    dp[i] = 0;
    if (n % 2 == 0) {
      bool ok = true;
      rep1(f, n) if (a[f][i] == hor) {
        ok = false;
        break;
      }
      if (ok) (dp[i] += dp[i - 1]) %= rem;
    }
    if (i > 1) {
      dp1[0][0] = 1;
      dp1[0][1] = 0;
      rep1(f, n) {
        dp1[f][0] = dp1[f][1] = 0;
        if (a[f][i] != ver and a[f][i - 1] != ver) {
          (dp1[f][1] += dp1[f - 1][0] + dp1[f - 1][1]) %= rem;
        }
        if (f == 1) continue;
        if (a[f][i] != hor and a[f - 1][i] != hor and a[f][i - 1] != hor and a[f - 1][i - 1] != hor) {
          (dp1[f][0] += dp1[f - 2][0]) %= rem;
          (dp1[f][1] += dp1[f - 2][1]) %= rem;
        }
      }
      // rep1(f, n) clog << "dp1 " << i << ' ' <<f << ' ' << dp1[f] << endl;
      (dp[i] += dp[i - 2] * dp1[n][1] % rem) %= rem;
    }
  }
  // rep1(i, m) clog << "dp " << i << ' ' << dp[i] << endl;
  cout << dp[m];
  
  return 0;
}