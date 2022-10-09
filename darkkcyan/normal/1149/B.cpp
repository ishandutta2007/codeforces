#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define maxn 101010
int n, q;
string wou;
int nxt[maxn][26];

int dp[300][300][300];
string des[3];

int cal(int a, int b, int c) {
  if (dp[a][b][c] != -1) return dp[a][b][c];
  if (a == 0 and b == 0 and c == 0) return 0;
  dp[a][b][c] = maxn;
  if (a) dp[a][b][c] = min(dp[a][b][c], nxt[cal(a - 1, b, c)][des[0][a - 1] - 'a']);
  if (b) dp[a][b][c] = min(dp[a][b][c], nxt[cal(a, b - 1, c)][des[1][b - 1] - 'a']);
  if (c) dp[a][b][c] = min(dp[a][b][c], nxt[cal(a, b, c - 1)][des[2][c - 1] - 'a']);
  // clog << ' ' << a << ' ' << b << ' ' << c << ' ' << dp[a][b][c] << endl;
  return dp[a][b][c];
}

void rem(int r) {
  for (int i = (r == 0) ? len(des[0]) : 0; i <= len(des[0]); ++i) {
    for (int f = (r == 1) ? len(des[1]) : 0; f <= len(des[1]); ++f) {
      for (int g = (r == 2) ? len(des[2]) : 0; g <= len(des[2]); ++g) {
        dp[i][f][g] = -1;
      }
    }
  }
  des[r].pop_back();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    cin >> wou;
    wou = ' ' + wou;
    rep(i, 26) nxt[len(wou) - 1][i] = nxt[len(wou)][i] = len(wou);
    for (int i = len(wou) - 1; i--; ) {
      memcpy(nxt[i], nxt[i + 1], sizeof nxt[i]);
      nxt[i][wou[i + 1] - 'a'] = i + 1;
    }
    memset(dp, -1, sizeof(dp));
    while (q--) {
      char op; int r;
      cin >> op >> r; --r;
      if (op == '+') {
        char c; cin >> c;
        des[r] += c;
      } else {
        rem(r);
      }
      int t = cal(len(des[0]), len(des[1]), len(des[2]));
      // clog << op << ' ' << r << ' ' <<  t << endl;
      if (t < len(wou)) cout << "YES\n";
      else cout << "NO\n";
    }

    return 0;
}