#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t shift=1;
int64_t X,D;

std::vector<int64_t> vs;

void output(int64_t v){
  while(v-->0){
    vs.push_back(shift);
  }
  shift+=D;
}

int main(){
  scanf("%I64d %I64d",&X,&D);
  for(int64_t k=60;k>0;k--){
    int64_t skew=((1LL<<k)-1);
    while(X>=skew){
      X-=skew;
      output(k);
    }
  }
  printf("%I64d\n",int64_t(vs.size()));
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%I64d",vs[i]);
  }
  printf("\n");
  return 0;
}