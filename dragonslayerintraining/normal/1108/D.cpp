#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

void setmin(int& x,int y){
  x=std::min(x,y);
}

char str[200005];
int dp[200005][3];

const char* rgb="RGB";

int main(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  for(int i=1;i<=N;i++){
    for(int t=0;t<3;t++){
      dp[i][t]=INF;
    }
  }
  for(int i=0;i<N;i++){
    int h=std::find(rgb,rgb+3,str[i])-rgb;
    for(int t=0;t<3;t++){
      setmin(dp[i+1][(t+1)%3],dp[i][t]+(t!=h));
      setmin(dp[i+1][(t+2)%3],dp[i][t]+(t!=h));
    }
  }
  int* best=std::min_element(dp[N],dp[N]+3);
  int c=best-dp[N];
  for(int i=N-1;i>=0;i--){
    int h=std::find(rgb,rgb+3,str[i])-rgb;
    str[i]='-';
    for(int t=0;t<3;t++){
      if(((t+1)%3==c)&&dp[i+1][(t+1)%3]==(dp[i][t]+(t!=h))||
	 ((t+2)%3==c)&&dp[i+1][(t+2)%3]==(dp[i][t]+(t!=h))){
	c=t;
	str[i]=rgb[c];
	break;
      }
    }
  }
  printf("%d\n",*best);
  printf("%s\n",str);
  return 0;
}