#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t left[100005];
int64_t right[100005];
int64_t N,D,B;

int64_t count_left(int64_t X){
  int64_t rem=0;
  int64_t bad=0;
  for(int64_t i=1;i<=(N+1)/2;i++){
    rem+=std::min(X,left[i]);
    X-=std::min(X,left[i]);
    if(rem>=B){
      rem-=B;
    }else{
      bad++;
    }
  }
  return bad;
}

int64_t count_right(int64_t X){
  int64_t rem=0;
  int64_t bad=0;
  for(int64_t i=N;i>(N+1)/2;i--){
    rem+=std::min(X,right[i]);
    X-=std::min(X,right[i]);
    if(rem>=B){
      rem-=B;
    }else{
      bad++;
    }
  }
  return bad;
}

int main(){
  scanf("%I64d %I64d %I64d",&N,&D,&B);
  for(int64_t i=1;i<=N;i++){
    int64_t A;
    scanf("%I64d",&A);
    left[i-i*D/(D+1)]+=A;
    right[i+(N+1-i)*D/(D+1)]+=A;
  }
  int64_t low=0,high=N*B+1;
  int64_t best=0;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    int64_t lcnt=count_left(mid);
    int64_t rcnt=count_right(N*B-mid);
    best=std::max(best,std::min(lcnt,rcnt));
    if(lcnt<rcnt){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%I64d\n",best);
  return 0;
}