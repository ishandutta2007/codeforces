#include <cstdio>
#include <algorithm>
#include <numeric>

const int MOD = 998244353;

int fs[500005];//fs[x] = count [0,x)
int gs[500005];//gs[x] = count [0,x)+{x+1}

void solve(){
  int N;
  scanf("%d",&N);
  std::fill(fs,fs+N+2,0);
  std::fill(gs,gs+N+2,0);
  fs[0]=1;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A>0){
      gs[A-1]=(gs[A-1]*2LL+fs[A-1])%MOD;
    }
    fs[A+1]=(fs[A+1]*2LL+fs[A])%MOD;
    gs[A+1]=gs[A+1]*2%MOD;
  }
  /*
  for(int i=0;i<N+2;i++){
    printf("fs[%d]=%d gs[%d]=%d\n",i,fs[i],i,gs[i]);
  }
  */
  printf("%lld\n",(std::accumulate(fs+1,fs+N+2,0LL)+std::accumulate(gs,gs+N+2,0LL))%MOD);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}