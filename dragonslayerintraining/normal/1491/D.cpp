#include <cstdio>

const int INF=1e9+7;

bool can(int src,int dest){
  //dp[k][carry]: can convert suffix of k bits from src to dest with given carry
  bool dp[32][32]={};
  dp[0][0]=true;
  for(int k=0;k<31;k++){
    for(int c=0;c<30;c++){
      int old=c+((src>>k)&1)-((dest>>k)&1);
      for(int d=old-old/2;d<=old;d++){
	dp[k+1][d]|=dp[k][c];
      }
    }
  }
  return dp[31][0];
}

int main(){
  int N;
  scanf("%d",&N);
  while(N--){
    int U,V;
    scanf("%d %d",&U,&V);
    if(can(U,V)){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}