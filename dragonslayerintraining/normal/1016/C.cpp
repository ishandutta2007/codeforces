#include <cstdio>
#include <stdint.h>
#include <algorithm>

int64_t as[300005];
int64_t bs[300005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&bs[i]);
  }
  int64_t sum=0;
  int64_t loop1=0,loop2=0;
  for(int64_t i=0;i<N;i++){
    sum+=as[i];
    loop1+=i*as[i];
    loop2+=(N*2-1-i)*as[i];
    
    sum+=bs[i];
    loop1+=(N*2-1-i)*bs[i];
    loop2+=i*bs[i];
  }
  //fprint64_tf(stderr,"%I64d,%I64d,%I64d\n",sum,loop1,loop2);
  int64_t best=loop1;
  int64_t prefix=0;
  for(int64_t i=0;i<N;i++){
    if(i%2==0){
      prefix+=as[i]*i*2+bs[i]*(i*2+1);
    }else{
      prefix+=as[i]*(i*2+1)+bs[i]*(i*2);
    }
    sum-=(as[i]+bs[i]);
    loop1-=(2*(N-i)-1)*bs[i];
    loop2-=(2*(N-i)-1)*as[i];
    loop1-=sum;
    loop2-=sum;
    int64_t loop=(i%2==0)?loop2:loop1;
    //print64_tf("%I64d: %I64d+%I64d+%I64d = %I64d\n",i,prefix,2*(i+1)*sum,loop,prefix+2*(i+1)*sum+loop);
    best=std::max(best,prefix+2*(i+1)*sum+loop);
  }
  printf("%I64d\n",best);
  return 0;
}