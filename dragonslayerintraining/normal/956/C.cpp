#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t as[100005];

int64_t before[100005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t marks=0;
  for(int64_t i=0;i<N;i++){
    marks=std::max(marks,as[i]);
    before[i]=marks;
    //printf("Before[%I64d]=%I64d\n",i,before[i]);
    marks=std::max(marks,as[i]+1);
  }
  int64_t total=0;
  for(int64_t i=N-1;i>=0;i--){
    //printf("After as[%I64d]=%I64d: %I64d marks: +%I64d\n",i,as[i],marks,marks-as[i]-1);
    total+=marks-as[i]-1;
    if(marks>before[i]){
      marks--;
    }
  }
  printf("%I64d\n",total);
  return 0;
}