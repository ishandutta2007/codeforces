#include <cstdio>
#include <algorithm>
#include <cassert>

using ll=long long;

const ll INF=1e15+7;

int N;
ll cs[201][201];
ll dp[201][201];

ll getrect(int i1,int i2,int j1,int j2){
  i1--,j1--;
  return cs[i2][j2]-cs[i1][j2]-cs[i2][j1]+cs[i1][j1];
}

int par[201];

int recover(int l,int r){
  if(l>r) return 0;
  for(int m=l;m<=r;m++){
    if(dp[l][r]==dp[l][m-1]+dp[m+1][r]+getrect(l,r,1,l-1)+getrect(l,r,r+1,N)){
      par[recover(l,m-1)]=m;
      par[recover(m+1,r)]=m;
      return m;
    }
  }
  assert(0);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      scanf("%lld",&cs[i][j]);
      cs[i][j]+=cs[i-1][j]+cs[i][j-1]-cs[i-1][j-1];
    }
  }
  for(int l=N;l>=1;l--){
    for(int r=l;r<=N;r++){
      dp[l][r]=INF;
      for(int m=l;m<=r;m++){
	dp[l][r]=std::min(dp[l][r],dp[l][m-1]+dp[m+1][r]+getrect(l,r,1,l-1)+getrect(l,r,r+1,N));
      }
    }
  }
  par[recover(1,N)]=0;
  for(int i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%d",par[i]);
  }
  printf("\n");
}