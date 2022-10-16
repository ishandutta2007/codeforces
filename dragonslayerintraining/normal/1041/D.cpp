#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t start[200005];
int64_t end[200005];

int main(){
  int64_t N,H;
  scanf("%I64d %I64d",&N,&H);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d",&start[i],&end[i]);
  }
  start[N]=end[N]=2e9+7;
  int64_t x1=-1e9;
  int64_t x2=x1+H;
  int64_t i=0,j=0;
  int64_t best=H;
  while(i<N){
    int64_t skip=std::min(start[i]-x1,start[j]-x2);
    x1+=skip;
    x2+=skip;
    if(x1>=start[i]) x1=end[i++];
    if(x2>=start[j]) x2=end[j++];
    best=std::max(best,x2-x1);
  }
  printf("%I64d\n",best);
  return 0;
}