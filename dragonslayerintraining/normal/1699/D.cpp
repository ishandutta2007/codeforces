#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int as[5005];
int freq[5005];
int dp[5005];


void solve(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  std::fill(dp,dp+N+1,-INF);
  dp[N+1]=-1;
  for(int l=N+1;l>=1;l--){
    int common=0;
    for(int r=l;;r++){
      if(((r-l)%2==0)&&(common<=(r-l)/2)){
	//printf("[%d,%d) removable\n",l,r);
	if(l==1||r==N+1||as[l-1]==as[r]){
	  //printf("[%d,%d) removed\n",l,r);
	  dp[l-1]=std::max(dp[l-1],dp[r]+1);
	}
      }
      if(r==N+1) break;
      common=std::max(common,++freq[as[r]]);
    }
    //printf("dp[%d]=%d\n",l,dp[l]);
    for(int r=l;r<=N;r++){
      freq[as[r]]=0;
    }
  }
  printf("%d\n",dp[0]);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}