#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const int fivetosix = 5*5*5*5*5*5; // 5^6
int n, m;
int a[7], b[7];
int c[7][7];
int dp[7][7][5][fivetosix];

int dpow(int b, int p) {
  int ans = 1;
  for (; p; p--) {
    ans *= b;
  }
  return ans;
}

int flows[6];
int compress() {
  int x = 0;
  for (int i=5; i>=0; --i) {
    x = x*5 + flows[i];
  }
  return x;
}
void decompress(int x) {
  for (int i=0; i<=5; ++i) {
    flows[i] = x%5;
    x /= 5;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  memset(dp, INF, sizeof dp);
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=m; ++i) {
    cin >> b[i];
  }
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=m; ++j) {
      cin >> c[i][j];
    }
  }

  int fpow = dpow(5, n);
  //cerr << " FPOW " << fpow << endl;
  dp[1][0][0][0] = 0;
  for (int j=1; j<=m; ++j) {
    for (int i=0; i<n; ++i) {
      for (int r=0; r<=b[j]; ++r) {
        for (int f=0; f<fpow; ++ f) {
          dp[j][i+1][r][f] = min(dp[j][i+1][r][f], dp[j][i][r][f]);
          decompress(f);
          //cerr << " dp " << j << "," << i << "," << r << ",{";
          //for (int x=0; x<n; ++x) {
            //cerr << flows[x] << ",";
          //}
          //cerr << "} = " << dp[j][i][r][f] << endl;
          int fi = flows[i];
          for (int x=1; x+fi <= a[i+1] && x+r <= b[j]; ++x) {
            flows[i] = x+fi;
            dp[j][i+1][r+x][compress()] = min(dp[j][i+1][r+x][compress()], dp[j][i][r][f] + c[i+1][j]);
            //cerr << " UPD " << j << "," << i+1 << "," << r+x << "," << compress() << endl;
          }
          flows[i] = fi;
        }
      }
    }
      for (int r=0; r<=b[j]; ++r) {
        for (int f=0; f<fpow; ++ f) {
          decompress(f);
          //cerr << " dp " << j << "," << n << "," << r << ",{";
          //for (int x=0; x<n; ++x) {
            //cerr << flows[x] << ",";
          //}
          //cerr << "} = " << dp[j][n][r][f] << endl;
    if (j != m) {
          dp[j+1][0][0][f] = min(dp[j+1][0][0][f], dp[j][n][r][f]);
    }
        }
      }
  }
  
  {
    int j = m;
    int i = n;
    for (int i=0; i<n; ++i) {
      flows[i] = a[i+1];
    }
    int f = compress();
    int best = INF;
    for (int r=0; r<=b[m]; ++r) {
      //cerr << " Q " << j << "," << i << "," << r << "," << f << endl;
      best = min(best, dp[j][i][r][f]);
    }
    if (best == INF) {
      cout << "-1\n";
    } else {
      cout << best << "\n";
    }
  }

  return 0;
}