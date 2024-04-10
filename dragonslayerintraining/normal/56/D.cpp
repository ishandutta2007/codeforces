#include <iostream>
#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

void setmin(int& x,int y){x=std::min(x,y);}
int dp[1005][1005];

std::string S,T;

void recover(int i,int j){
  if(i==0&&j==0) return;
  if(i>0&&dp[i][j]==dp[i-1][j]+1){
    recover(i-1,j);
    printf("DELETE %d\n",j+1);
  }else if(j>0&&dp[i][j]==dp[i][j-1]+1){
    recover(i,j-1);
    printf("INSERT %d %c\n",j,T[j-1]);
  }else{
    if(i>0&&j>0){
      if(S[i-1]==T[j-1]&&dp[i][j]==dp[i-1][j-1]){
	recover(i-1,j-1);
      }else if(S[i-1]!=T[j-1]&&dp[i][j]==dp[i-1][j-1]+1){
	recover(i-1,j-1);
	printf("REPLACE %d %c\n",j,T[j-1]);
      }
    }
  }
}

int main(){
  std::cin>>S>>T;
  for(int i=0;i<=S.length();i++){
    for(int j=0;j<=T.length();j++){
      if(i==0&&j==0) continue;
      dp[i][j]=INF;
      if(i>0) setmin(dp[i][j],dp[i-1][j]+1);
      if(j>0) setmin(dp[i][j],dp[i][j-1]+1);
      if(i>0&&j>0){
	if(S[i-1]==T[j-1]){
	  setmin(dp[i][j],dp[i-1][j-1]);
	}else{
	  setmin(dp[i][j],dp[i-1][j-1]+1);
	}
      }
    }
  }
  printf("%d\n",dp[S.length()][T.length()]);
  recover(S.length(),T.length());
  return 0;
}