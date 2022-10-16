#include <cstdio>
#include <algorithm>

long long vs[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%lld",&vs[i]);
  }
  long long lb=0;
  for(int i=1;i<N;i++){
    vs[i]+=vs[i-1];
  }
  for(int i=0;i<N;i++){
    lb=std::max(lb,(vs[i]+i)/(i+1));
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T<lb){
      printf("-1\n");
    }else{
      printf("%lld\n",(vs[N-1]+T-1)/T);
    }
  }
}