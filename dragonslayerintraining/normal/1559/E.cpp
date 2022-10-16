#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int ls[50],rs[50];

int mem[2][100005];
int *dp=mem[0],*next=mem[1];

int ans[100005];
int N,M;

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d %d",&ls[i],&rs[i]);
  }
  for(int g=1;g<=M;g++){
    std::fill(dp,dp+M/g+1,1);
    for(int i=0;i<N;i++){
      int L=(ls[i]+g-1)/g,R=rs[i]/g+1;
      int sum=0;
      for(int j=0;j<=M/g;j++){
	if(j>=L) sum=(sum+dp[j-L])%MOD;
	if(j>=R) sum=(sum-dp[j-R])%MOD;
	next[j]=sum;
      }
      std::swap(dp,next);
    }
    ans[g]=dp[M/g];
  }
  for(int i=M;i>=1;i--){
    for(int j=i*2;j<=M;j+=i){
      ans[i]=(ans[i]-ans[j])%MOD;
    }
  }
  printf("%d\n",(ans[1]+MOD)%MOD);
}