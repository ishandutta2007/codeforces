#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const int N = 200200;
const int K = 17;
int f[1<<K];
int dp[N][K];
int g[N];
int r[N][K];
char s[N];

int n, k;

int check(int j, int i, int m) {
  int oth = INF;
  if (i+m-1 <= n) {
    oth = g[i+m-1] - g[i-1] - (r[i+m-1][j] - r[i-1][j]);
    //cerr << " !! " << g[i+m-1] << " - " << g[i-1] << " - (" << r[i+m-1][j] << " - " << r[i-1][j] << ")" << endl;
  }
  //cerr << " HOW MANY WRONG CHARS IN [" << i << ".." << i+m-1 << "] FOR CHAR " << (char) ('a' + j) << " ? : " << oth << endl;
  return oth;
}

bool solve(int m) {
  for (int i=0; i<k; ++i) {
    dp[n+1][i] = INF;
  }
  for (int i=n; i>=1; --i) {
    for (int j=0; j<k; ++j) {
      dp[i][j] = dp[i+1][j];
      int oth = check(j, i, m);
      if (oth == 0) {
        dp[i][j] = i+m-1;
      }
    }
  }

  f[0] = 0;
  for (int i=1; i<(1<<k); ++i) 
  {
    f[i] = INF;
    for (int j=0; j<k; ++j) {
      if (!(i&(1<<j))) {
        continue;
      }
      int p = i^(1<<j);
      if (f[p] > n) {
        continue;
      }
      f[i] = min(f[i], dp[f[p]+1][j]);
    }
  }
  return (f[(1<<k)-1] <= n);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  cin >> (s+1);
  for (int i=1; i<=n; ++i) {
    for (int j=0; j<k; ++j) {
      r[i][j] = r[i-1][j] + (s[i] == 'a'+j);
    }
    g[i] = g[i-1] + (s[i] != '?');
  }
  int lo = 0, hi = n;
  while (lo<hi) {
    int mid = (lo+hi+1)/2;
    if (solve(mid)) {
      lo = mid;
    } else {
      hi = mid-1;
    }
  }
  cout << lo << "\n";
  return 0;
}