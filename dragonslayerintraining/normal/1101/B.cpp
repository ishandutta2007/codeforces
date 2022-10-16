#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

void setmax(int& x,int y){
  x=std::max(x,y);
}

char str[500005];

int dp[5];

int main(){
  scanf("%s",str);
  std::fill(dp+1,dp+5,-INF);
  for(int i=0;str[i];i++){
    if(str[i]=='['){
      setmax(dp[1],dp[0]+1);
    }else if(str[i]==':'){
      setmax(dp[3],dp[2]+1);
      setmax(dp[2],dp[1]+1);
    }else if(str[i]=='|'){
      setmax(dp[2],dp[2]+1);
    }else if(str[i]==']'){
      setmax(dp[4],dp[3]+1);
    }
  }
  if(dp[4]>0){
    printf("%d\n",dp[4]);
  }else{
    printf("-1\n");
  }
  return 0;
}