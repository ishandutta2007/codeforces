#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long n;
long long dp[5000][5000] = {0};

int main() {
  cout << fixed;
  cin >> n;
  vector<long long> psum(5000, 1);
  long long ps = 1;
  dp[0][0] = 1;
  char p;
  cin >> p;
  for(long long i = 1; i<n; i++){
    char a;
    cin >> a;
    vector<long long> sum(5000, 0);
    long long s = 0;
    if(p == 'f'){
      for(long long k = 1; k<5000; k++){
        dp[i][k] = dp[i-1][k-1];
        dp[i][k] %= MOD;
        s += dp[i][k];
        s %= MOD;
        sum[k] = sum[k-1]+dp[i][k];
        sum[k] %= MOD;
      }
    }
    else{
      dp[i][0] = ps;
      s = ps;
      sum[0] = ps;
      for(long long k = 1; k<5000; k++){
        dp[i][k] = ps - psum[k-1];
        dp[i][k] %= MOD;
        s += dp[i][k];
        s %= MOD;
        sum[k] = sum[k-1] + dp[i][k];
        sum[k] %= MOD;
      }
    }
    p = a;
    ps = s;
    psum = sum;
    ps %= MOD;
    if(ps < 0) ps = MOD+ps;
  }
  cout << ps << endl;
}

/*
6
f
s
f
s
f
s

*/