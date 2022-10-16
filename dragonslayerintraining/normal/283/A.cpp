#include <vector>
#include <cstdio>
#include <stdint.h>

std::vector<int64_t> as(1);
int64_t total=0;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t T;
    scanf("%I64d",&T);
    switch(T){
    case 1:{
      int64_t A,X;
      scanf("%I64d %I64d",&A,&X);
      total+=A*X;
      as[A-1]+=X;
      break;
    }
    case 2:{
      int64_t K;
      scanf("%I64d",&K);
      as.back()-=K;
      as.push_back(K);
      total+=K;
      break;
    }
    case 3:{
      int64_t k=as.back();
      as.pop_back();
      as.back()+=k;
      total-=k;
      break;
    }
    }
    printf("%.10lf\n",static_cast<double>(total)/as.size());
  }
  return 0;
}