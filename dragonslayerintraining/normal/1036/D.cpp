#include <cstdio>
#include <set>
#include <stdint.h>

std::set<int64_t> prefix;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int64_t A=0;
  for(int64_t i=0;i<N;i++){
    int64_t X;
    scanf("%I64d",&X);
    A+=X;
    prefix.insert(A);
  }
  int64_t M;
  scanf("%I64d",&M);
  int64_t ans=0;
  int64_t B=0;
  for(int64_t i=0;i<M;i++){
    int64_t X;
    scanf("%I64d",&X);
    B+=X;
    if(prefix.count(B)){
      ans++;
    }
  }
  if(A==B){
    printf("%I64d\n",ans);
  }else{
    printf("-1\n");
  }
  return 0;
}