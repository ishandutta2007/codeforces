#include <cstdio>

const int MOD=1e9+7;

int pascal[1001][1001];

int cs[1000];

int main(){
  for(int i=0;i<=1000;i++){
    pascal[0][i]=1;
    pascal[i][0]=1;
  }
  for(int i=1;i<=1000;i++){
    for(int j=1;j<=1000;j++){
      pascal[i][j]=(pascal[i-1][j]+pascal[i][j-1])%MOD;
    }
  }
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  int balls=0;
  int ans=1;
  for(int i=0;i<N;i++){
    ans=1LL*ans*pascal[balls][cs[i]-1]%MOD;
    balls+=cs[i];
  }
  printf("%d\n",ans);
}