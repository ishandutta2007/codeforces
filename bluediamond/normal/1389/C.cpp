#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long

int f[10],dp[10][10];


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    string s;
    cin>>s;
    for (int i=0;i<10;i++) {
      f[i]=0;
      for (int j=0;j<10;j++) dp[i][j]=0;
    }
    for (auto &ch : s) {
      int x=ch-'0';
      f[x]++;
      for (int y=0;y<10;y++) {
        if (dp[x][y]&1) dp[x][y]++;
        if (!(dp[y][x]&1)) dp[y][x]++;
      }
    }
    int sol=0;
    for (int i=0;i<10;i++) {
      sol=max(sol,f[i]);
      f[i]=0;
      for (int j=0;j<10;j++) sol=max(sol,dp[i][j]-(int) 1e9*(i==j)-dp[i][j]%2),dp[i][j]=0;
    }
    cout<<(int)s.size()-sol<<"\n";
  }
  return 0;
}