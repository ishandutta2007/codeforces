#include <cstdio>
#include <algorithm>

int as[100000];

//0 if losing
//1 if winning
int dp[100001];
//0 if jump move to losing
//1 if all jump moves to winning
int ac=1;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  
  dp[N]=0;
  for(int i=N-1;i>=0;i--){
    if((i!=0)&&(as[i]!=as[i-1])){
      ac&=dp[i+1];
    }
    dp[i]=(dp[i+1]&ac)^1;
  }
  if(dp[0]){
    printf("Conan\n");
  }else{
    printf("Agasa\n");
  }
  return 0;
}