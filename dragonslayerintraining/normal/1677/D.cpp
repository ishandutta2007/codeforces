#include <cstdio>
#include <algorithm>

const int MOD=998244353;

int vs[1000006];

int solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&vs[i]);
  }
  for(int i=0;i<K;i++){
    if(vs[N-1-i]!=0&&vs[N-1-i]!=-1){
      return 0;
    }
  }
  int ways=1;
  for(int i=0;i<K;i++){
    ways=1LL*ways*(i+1)%MOD;
  }
  for(int i=K;i<N;i++){
    if(vs[i-K]==-1){
      ways=1LL*ways*(i+1)%MOD;
    }else if(vs[i-K]==0){
      ways=1LL*ways*std::min(K+1,i+1)%MOD;
    }
  }
  return ways;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%d\n",solve());
  }
}