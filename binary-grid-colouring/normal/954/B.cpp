#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[1234];
int dp[1234];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  scanf("%s",s+1);
  // int len = s.length();
  dp[1] = 1;
  int limit = 0;
  // int ans = 0;
  for(int i=2;i<=n;i++) {
    dp[i] = dp[i-1] + 1;
    if((i%2)==0)
    {
      // std::cout << "/* message */" << '\n';
       limit = i / 2;
      for(int j=1;j<=limit;j++) {

        if(s[j] != s[j + limit]) {
          break;
        }
        if(limit == j) {
          dp[i] = min(dp[i], i / 2 + 1);
        }
      }
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}
/*
7
abcabca
*/