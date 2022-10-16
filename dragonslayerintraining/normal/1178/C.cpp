#include <cstdio>

const int MOD=998244353;

int main(){
  int W,H;
  scanf("%d %d",&W,&H);
  int ans=1;
  for(int i=0;i<W+H;i++){
    ans=2LL*ans%MOD;
  }
  printf("%d\n",ans);
}