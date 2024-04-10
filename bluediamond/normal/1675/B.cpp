#include <bits/stdc++.h>

bool home = 1;

using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;

const int N=30+7;
const int INF=(int)1e9+7;
int n;
int a[N][N],dp[N][N];

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  home=0;

  if (home) {
    freopen("I_am_iron_man", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (int i=1;i<=n;i++) {
      cin>>a[i][0];
      for (int j=1;j<N;j++) {
        a[i][j]=a[i][j-1]/2;
      }
    }
    for (int i=0;i<N;i++) for(int j=0;j<N;j++) dp[i][j]=INF;
    for (int j=0;j<N;j++) {
      dp[1][j]=j;
    }

    for (int i=1;i<n;i++) {
      for(int j=0;j<N;j++) {
        for (int k=0;k<N;k++) {

          if (a[i][j]<a[i+1][k]) dp[i+1][k]=min(dp[i+1][k],dp[i][j]+k);
        }
      }
    }
    int sol=INF;
    for (int j=0;j<N;j++) sol=min(sol,dp[n][j]);
    if (sol==INF) sol=-1;
    cout<<sol<<"\n";
  }

}