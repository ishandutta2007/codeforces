#include <cstdio>
#include <stdint.h>

int64_t N;

int64_t query(int64_t X,int64_t Y){
  int64_t mid=(N*N+1)/2;
  if((X+Y)%2==0){
    if(Y%2==0){
      return Y/2*N+X/2;
    }else{
      return Y/2*N+X/2+(N+1)/2;
    }
  }else{
    if(Y%2==0){
      return mid+Y/2*N+X/2;
    }else{
      return mid+Y/2*N+X/2+N/2;
    }
  }
}

int main(){
  int64_t Q;
  scanf("%I64d %I64d",&N,&Q);
  while(Q-->0){
    int64_t X,Y;
    scanf("%I64d %I64d",&X,&Y);
    printf("%I64d\n",query(Y-1,X-1)+1);
  }
  return 0;
}