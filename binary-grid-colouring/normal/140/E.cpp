#include<bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;
const int maxn = 1001000;

int l[maxn],a[5201][5201],fac[5201],rfac[5201];
//int dp[5201][5201];
std::vector<int> dp[maxn];

int main(int argc, char const *argv[]) {
  int n,m,p;
  std::cin >> n >> m >> p;
  int sz = 0 ;
  for(int i=1;i<=n;i++) {
    std::cin >> l[i];
    //sz = max(l[i],sz);
    dp[i].resize(l[i]+1);
  }
  //  vector<vector<int>> dp(sz + 1, vector<int>(sz + 1, 0));
  fac[0] = 1;
  rfac[0] = 1;
  for(int i=1;i<=5010;i++) {
    fac[i] = 1LL * fac[i-1] * i % p;
    rfac[i] = 1LL * rfac[i-1] * (m - i + 1) % p ;
  }
  a[0][0] = 1;
  for(int i=1;i<=5010;i++) {
    for(int j=1;j<=i;j++) {
      a[i][j] = (a[i-1][j-1] + 1LL * a[i-1][j] * (j-1) % p) % p;
    }
  }
  int sum = 1;
  int ans = 0;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=l[i];j++) {
      dp[i][j] = 1LL * sum * rfac[j] % p * a[l[i]][j] % p;
      if(i > 1 && j <= l[i-1]) {
        dp[i][j] = (dp[i][j] - 1LL * dp[i-1][j] * a[l[i]][j] % p * fac[j] % p + p) % p;
      }
      ans = (ans + dp[i][j]) % p;
    }
    sum = ans;
    ans = 0;
  }
  std::cout << sum << '\n';
  return 0;
}