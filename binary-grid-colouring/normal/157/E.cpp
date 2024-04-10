#include<bits/stdc++.h>

using namespace std;
const int maxn = 2710;
const double eps = 1e-9;
const double pi = 3.1415926536;

int dp[maxn][maxn];
string s;

int main(int argc, char const *argv[]) {

  dp[0][0] = 1;
  for(int i = 1;i<=100;i++) {
    for(int j = 0; j <= (i-1)*26;j++){
      for(int k=0;k<26;k++) {
        dp[i][j+k] = (dp[i][j+k] + dp[i-1][j]) % 1000000007;
      }
    }
  }
  int t;
  std::cin >> t;
  while(t--) {
    std::cin >> s;
    int len ;
    len = s.size();
    int sum = 0;
    for(int i=0;i<len;i++) {
      sum += s[i] - 'a';
    }
    std::cout << dp[len][sum] -1 << '\n';
  }
  return 0;
}