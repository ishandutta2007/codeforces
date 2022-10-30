#include <bits/stdc++.h>
using namespace std;

int cnt(string s, int p, int n){
  int dp[n+1][n+1][27];
  int total[n+1][n+1];
  for(int a = 0; a<=n; a++){
    for(int b = 0; b<=n; b++){
      for(int k = 0; k<=26; k++){
        dp[a][b][k] = 0;
      }
      total[a][b] = 0;
    }
  }
  for(int i = 0; i<=n; i++){
    dp[i][0][26] = 1;
    total[i][0] = 1;
  }
  for(int i = 1; i<=n; i++){
    int t = s[i-1]-'a';
    for(int k = 1; k<=i; k++){
      int su = 0;
      for(int j = 0; j<26; j++){
        if(j == t){
          dp[i][k][j] = total[i-1][k-1];
        }
        else dp[i][k][j] = dp[i-1][k][j];
        su += dp[i][k][j];
      }
      total[i][k] = su;
    }
  }
  int mon = 0;
  int t = 0;
  //for(int i = 0; i<=n; i++) cout << total[n][i] << endl;
  for(int i = n; i>=0; i--){
    mon += total[n][i]*(n-i);
    t += total[n][i];
    if(t >= p){
      mon -= (n-i)*(t-p);
      t = p;
      break;
    }
  }
  if(t < p) return -1;
  return mon;
}

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  cout << cnt(s, k, n) << endl;
}