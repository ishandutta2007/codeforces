#include <cstdio>
#include <algorithm>
#include <climits>

char str[100005];
int dp[100005];

void solve(){
  int N,P,K;
  scanf("%d %d %d",&N,&P,&K);
  P--;
  scanf("%s",str);
  int X,Y;
  scanf("%d %d",&X,&Y);
  int best=INT_MAX;
  for(int i=N-1;i>=0;i--){
    dp[i]=(str[i]=='0');
    if(i+K<N){
      dp[i]+=dp[i+K];
    }
    if(i>=P){
      best=std::min(best,dp[i]*X+(i-P)*Y);
    }
  }
  printf("%d\n",best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}