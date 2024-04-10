#include <cstdio>
#include <stdint.h>

bool iscube(int64_t num){
  int64_t low=1,high=1000001;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(mid*mid*mid<=num){
      low=mid;
    }else{
      high=mid;
    }
  }
  return low*low*low==num;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A,B;
    scanf("%I64d %I64d",&A,&B);
    if(iscube(A*B)&&((A*A)%B==0)&&((B*B)%A==0)){
      printf("Yes\n");
    }
    else{
      printf("No\n");
    }
  }
}