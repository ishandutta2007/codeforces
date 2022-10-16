#include <cstdio>

const int MOD=998244353;

int hs[2005];
int poly[6005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  int diff=0;
  for(int i=0;i<N;i++){
    diff+=(hs[i]!=hs[(i+1)%N]);
  }
  int base[3]={1,K-2,1};
  poly[0]=1;
  for(int p=0;p<diff;p++){
    for(int i=6001;i>=0;i--){
      poly[i]=1LL*poly[i]*base[0]%MOD;
      if(i>=1) poly[i]=(poly[i]+1LL*poly[i-1]*base[1])%MOD;
      if(i>=2) poly[i]=(poly[i]+1LL*poly[i-2]*base[2])%MOD;
    }
  }
  int ans=0;
  for(int i=0;i<diff;i++){
    ans=(ans+poly[i])%MOD;
  }
  for(int i=0;i<N-diff;i++){
    ans=1LL*ans*K%MOD;
  }
  printf("%d\n",ans);
}