#include <cstdio>

const int MOD=998244353;

int N,X;

int pascal[501][501];
int ways[501][501];

int ipow(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int main(){
  for(int i=0;i<=500;i++){
    pascal[i][0]=pascal[0][i]=1;
  }
  for(int i=1;i<=500;i++){
    for(int j=1;j<=500;j++){
      pascal[i][j]=(pascal[i-1][j]+pascal[i][j-1])%MOD;
    }
  }
  scanf("%d %d",&N,&X);
  for(int i=1;i<=X;i++){
    ways[i][1]=i;
    for(int j=2;j<=N;j++){
      if(i>=j){
	for(int k=1;k<=j;k++){
	  ways[i][j]=(ways[i][j]+1LL*pascal[k][j-k]*ways[i-(j-1)][k]%MOD*ipow(j-1,j-k))%MOD;
	}
      }
    }
  }
  printf("%d\n",(ipow(X,N)+MOD-ways[X][N])%MOD);
}