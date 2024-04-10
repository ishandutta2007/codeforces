#include<bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;
#define  pii pair<int,int>
#define fi first
#define se second

int n,m;
string tmp;

int dp[5001][5001];
int main(int argc, char const *argv[]) {
  int n;
  char ch;
  std::cin >> n;
  dp[0][0] = 1;
  for(int i=0;i<n;i++) {
    if(ch=='f'){
      for(int j=0;j<=i;j++) {
        dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % mod;
      }
    }
    else
    {
      int sum = 0;
      for(int j=i;j>=0;--j) {
        sum = (sum + dp[i][j]) % mod;
        dp[i+1][j]  = (dp[i+1][j] + sum) % mod;
      }
    }
    cin>>ch;
  }
  int ans = 0;
  for(int i=0;i<=n;i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  std::cout << ans << '\n';
  return 0;
}