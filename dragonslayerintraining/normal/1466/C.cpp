#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF=1e9+7;

char str[100005];

void solve(){
  scanf("%s",str);
  int N=strlen(str);
  int dp[4]={INF,INF,INF,0};
  for(int i=0;i<N;i++){
    int next[4]={INF,INF,INF,INF};
    for(int s=0;s<8;s++){
      bool good=true;
      for(int j=0;j<3;j++){
	for(int k=j+1;k<3;k++){
	  if(((s&(1<<j))==0)&&
	     ((s&(1<<k))==0)&&
	     (i>=j)&&(i>=k)&&
	     (str[i-j]==str[i-k])){
	    good=false;
	  }
	}
      }
      if(good){
	next[s&3]=std::min(next[s&3],dp[s>>1]+(s&1));
      }
    }
    //printf("%c\n",str[i]);
    for(int k=0;k<4;k++){
      dp[k]=next[k];
      //printf("dp[%d]=%d\t",k,dp[k]);
    }
    //printf("\n");
  }
  printf("%d\n",*std::min_element(dp,dp+4));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}