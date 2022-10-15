#include <bits/stdc++.h>

using namespace std;

bool home = 1;

//#define int ll

typedef long long ll;
typedef long double ld;

const int N=30000+7;
const int K=200+7;
const int INF=(int)1e9;
int n,kmax,pre[N],dp[N][K][2],suf[N][K][2],a[N][K],b[N][K],c[N][K],d[N][K];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  for (int l=0;l<N;l++){
    for (int k=0;k<K;k++){
      dp[l][k][0]=-INF;
      dp[l][k][1]=-INF;
      suf[l][k][0]=-INF;
      suf[l][k][1]=-INF;
      a[l][k]=-INF;
      b[l][k]=-INF;
      c[l][k]=-INF;
      d[l][k]=-INF;
    }
  }

  cin>>n>>kmax;
  for (int i=1;i<=n;i++){
    cin>>pre[i];
    pre[i]+=pre[i-1];
  }

  int mnpre=pre[n],mxpre=pre[n];


  for (int l=n;l>=1;l--){
    mnpre=min(mnpre,pre[l]);
    mxpre=max(mxpre,pre[l]);
    dp[l][1][0]=max(dp[l][1][0],-mnpre+pre[l-1]);
    dp[l][1][1]=max(dp[l][1][1],mxpre-pre[l-1]);


    for (int k=1;k<=kmax;k++){
      a[l][k]=max(a[l+1][k],suf[l+1][k-1][1]-2*pre[l]);
      b[l][k]=max(b[l+1][k],suf[l+1][k-1][0]+2*pre[l]);

      c[l][k]=max(c[l+1][k],suf[l+1][k-1][0]+pre[l]);
      d[l][k]=max(d[l+1][k],suf[l+1][k-1][1]-pre[l]);
    }

    for (int k=2;k<=kmax-1;k++){
      dp[l][k][0]=a[l][k]+pre[l-1];
      dp[l][k][1]=b[l][k]-pre[l-1];
      dp[l][k][0]=max(dp[l][k][0],suf[l+1][k-1][0]-pre[l-1]);
      dp[l][k][1]=max(dp[l][k][1],suf[l+1][k-1][1]+pre[l-1]);
      dp[l][k][0]+=pre[l-1];
      dp[l][k][1]-=pre[l-1];
    }
    {
      int k=kmax;
      dp[l][k][0]=max(dp[l][k][0],c[l][k]-pre[l-1]);
      dp[l][k][0]=max(dp[l][k][0],d[l][k]+pre[l-1]);
    }
    for (int k=1;k<=kmax;k++){
      suf[l][k][0]=max(suf[l+1][k][0],dp[l][k][0]);
      suf[l][k][1]=max(suf[l+1][k][1],dp[l][k][1]);
    }
  }
  cout<<suf[1][kmax][0]<<"\n";



  return 0;
}