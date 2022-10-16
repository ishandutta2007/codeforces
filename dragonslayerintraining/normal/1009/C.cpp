#include <cstdio>
#include <queue>
#include <stdint.h>

int64_t N,M;

int64_t split(int64_t k){
  return (k*(k+1)/2+(N-k-1)*(N-k)/2);
}

int main(){
  scanf("%I64d %I64d",&N,&M);
  std::queue<int64_t> sum;
  int64_t min=split(N/2);
  int64_t max=split(0);
  //printf("%I64d,%I64d",min,max);
  for(int64_t i=0;i<M;i++){
    int64_t X,D;
    scanf("%I64d %I64d",&X,&D);
    int64_t inc=X*N+std::max(min*D,max*D);
    //printf("INCREASE by %I64d\n",inc);
    sum.push(inc);
  }
  while(sum.size()>1){
    int64_t x=sum.front();
    sum.pop();
    int64_t y=sum.front();
    sum.pop();
    sum.push(x+y);
  }
  printf("%.10lf\n",(double)sum.front()/N);
  return 0;
}