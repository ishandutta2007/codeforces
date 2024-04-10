#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdint.h>

char str[1000006];
int64_t dp[1000006][4];

int main(){
  scanf("%s",str);
  int N=strlen(str);
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    std::copy(dp[i],dp[i]+4,dp[i+1]);
    if(i>0&&str[i-1]=='v'&&str[i]=='v'){
      dp[i+1][3]+=dp[i-1][2];
    }
    if(str[i]=='o'){
      dp[i+1][2]+=dp[i][1];
    }
    if(i>0&&str[i-1]=='v'&&str[i]=='v'){
      dp[i+1][1]+=dp[i-1][0];
    }
  }
  printf("%I64d\n",dp[N][3]);
  return 0;
}