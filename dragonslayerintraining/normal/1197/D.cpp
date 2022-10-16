#include <cstdio>
#include <algorithm>

const long long INF=1e9+7;

long long as[300005];

long long best[10];

template<class T>
void setmax(T& x,T y){
  x=std::max(x,y);
}

template<class T>
T ceildiv(T x,T y){
  return (x>=0)?(x+y-1)/y:x/y;
}

int main(){
  long long N,M,K;
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  std::fill(best,best+M,-INF);
  long long ans=0;
  for(int i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    as[i]+=as[i-1];
  }
  for(int i=0;i<=N;i++){
    for(int r=0;r<M;r++){
      setmax(ans,as[i]-ceildiv<long long>(i-r,M)*K+best[r]);
    }
    setmax(best[i%M],-as[i]+i/M*K);
  }
  printf("%I64d\n",ans);
}