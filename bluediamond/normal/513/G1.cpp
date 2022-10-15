#include <bits/stdc++.h>


using namespace std;

typedef long double ld;
const int N=30+1;
int n,k,perm[N];
ld p[N][N];
ld np[N][N];
ld transition[N][N][N][N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt","r",stdin);
#endif // ONLINE_JUDGE

  cin>>n>>k;
  for (int i=1;i<=n;i++) {
    cin>>perm[i];
  }

  ld tot=n*(n+1)/2;
  tot=1/tot;

  for (int l=1;l<=n;l++) {
    for (int r=l;r<=n;r++) {
      for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
          int nw_i=i;
          int nw_j=j;
          if(l<=i&&i<=r)nw_i=r+l-i;
          if(l<=j&&j<=r)nw_j=r+l-j;
          transition[i][j][nw_i][nw_j]+=tot;
        }
      }
    }
  }

  ld sol=0;

  for (int x=1;x<=n;x++) {
    for(int y=1;y<=n;y++){
      if(perm[x]>perm[y]){
        for (int i=1;i<=n;i++) {
          for(int j=1;j<=n;j++) {
            p[i][j]=np[i][j]=0;
          }
        }
        p[x][y]=1;
        for (int iter=1;iter<=k;iter++) {
          for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
              for (int ni=1;ni<=n;ni++){
                for (int nj=1;nj<=n;nj++) {
                  np[ni][nj]+=p[i][j]*transition[i][j][ni][nj];
                }
              }
            }
          }
          for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
              p[i][j]=np[i][j];
              np[i][j]=0;
            }
          }
        }
        for (int i=1;i<=n;i++) {
          for (int j=1;j<=n;j++) {
            if(i<j){
              sol+=p[i][j];
            }
          }
        }
      }
    }
  }

  cout<<fixed<<setprecision(9)<<sol<<"\n";
  return 0;
}