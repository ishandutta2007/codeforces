#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

char str[100005];
int adj[20][20];

int dp[1<<20];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  scanf("%s",str);
  for(int i=0;i<N-1;i++){
    adj[str[i]-'a'][str[i+1]-'a']++;
    adj[str[i+1]-'a'][str[i]-'a']++;
  }
  dp[0]=0;
  for(int i=1;i<(1<<M);i++){
    int pop=__builtin_popcount(i);
    dp[i]=INF;
    for(int k=0;k<M;k++){
      if((i&(1<<k))==0) continue;
      int scale=0;
      for(int l=0;l<M;l++){
	if(l==k) continue;
	if(i&(1<<l)){
	  scale+=adj[k][l];
	}else{
	  scale-=adj[k][l];
	}
      }
      dp[i]=std::min(dp[i],dp[i^(1<<k)]+pop*scale);
    }
    //printf("dp[%d]=%d\n",i,dp[i]);
  }
  printf("%d\n",dp[(1<<M)-1]);
}