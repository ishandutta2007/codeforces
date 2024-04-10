#include <cstdio>

char road[300005];
int dp[300005]={1};
int ac=1;

int main(){
  int N,K;
  scanf("%d %d %s",&N,&K,road);
  for(int i=1;i<N;i++){
    if(road[i]=='.'){
      dp[i]=(ac>0);
    }else{
      dp[i]=0;
    }
    ac+=dp[i];
    if(i>=K){
      ac-=dp[i-K];
    }
  }
  if(dp[N-1]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}