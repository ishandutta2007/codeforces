#include <cstdio>

char str[200];

int dp[3];

int main(){
  scanf("%s",str);
  for(int i=0;str[i];i++){
    if(str[i]=='Q'){
      dp[0]++;
      dp[2]+=dp[1];
    }else if(str[i]=='A'){
      dp[1]+=dp[0];
    }
  }
  printf("%d\n",dp[2]);
  return 0;
}