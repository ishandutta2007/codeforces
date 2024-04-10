#include <cstdio>
#include <numeric>

const int MOD=1e9+7;

int dp1[52][52][2500];
int dp2[52][2500];

int nonadj[52][52][52][3];

void addmod(int& x,long long y){
  x=(x+y)%MOD;
}

int main(){
  dp1[0][0][0]=1;
  dp2[0][0]=1;
  int N,T;
  scanf("%d %d",&N,&T);
  for(int i=0;i<N;i++){
    int T,G;
    scanf("%d %d",&T,&G);
    if(G==1){
      for(int a=50;a>=1;a--){
	for(int b=50;b>=0;b--){
	  for(int t=2500;t>=T;t--){
	    addmod(dp1[a][b][t],dp1[a-1][b][t-T]);
	  }
	}
      }
    }else if(G==2){
      for(int a=50;a>=0;a--){
	for(int b=50;b>=1;b--){
	  for(int t=2500;t>=T;t--){
	    addmod(dp1[a][b][t],dp1[a][b-1][t-T]);
	  }
	}
      }
    }else{
      for(int c=50-1;c>=1;c--){
	for(int t=2500;t>=T;t--){
	  addmod(dp2[c][t],dp2[c-1][t-T]);
	}
      }
    }	
  }
  nonadj[1][0][0][0]=1;
  nonadj[0][1][0][1]=1;
  nonadj[0][0][1][2]=1;
  for(int a=0;a<=50;a++){
    for(int b=0;b<=50;b++){
      for(int c=0;c<=50;c++){
	for(int last=0;last<3;last++){
	  if(last!=0) addmod(nonadj[a+1][b][c][0],nonadj[a][b][c][last]*(a+1LL));
	  if(last!=1) addmod(nonadj[a][b+1][c][1],nonadj[a][b][c][last]*(b+1LL));
	  if(last!=2) addmod(nonadj[a][b][c+1][2],nonadj[a][b][c][last]*(c+1LL));
	}
      }
    }
  }
  int ans=0;
  for(int a=0;a<=50;a++){
    for(int b=0;b<=50;b++){
      for(int c=0;c<=50;c++){
	for(int t=0;t<=T;t++){
	  if(dp1[a][b][t]&&dp2[c][T-t]){
	    int ways=std::accumulate(nonadj[a][b][c],nonadj[a][b][c]+3,0LL)%MOD;
	    //printf("%d,%d,%d: +%dx%dx%d\n",a,b,c,dp1[a][b][t],dp2[c][T-t],ways);
	    ans=(ans+1LL*dp1[a][b][t]*dp2[c][T-t]%MOD*ways)%MOD;
	  }
	}
      }
    }
  }
  printf("%d\n",ans);
}