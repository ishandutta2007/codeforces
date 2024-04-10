#include <cstdio>
#include <algorithm>
#include <cassert>
#include <stdint.h>

int64_t cnt[9];
int64_t hold[9];

const int SIZE=8*5+7*4+6*3+5*2+4*1;

int8_t dp[SIZE+1];

void add(int64_t size,int64_t amount){
  //printf("+%I64d x%I64d\n",size,amount);
  for(int64_t i=SIZE;i>=0;i--){
    if(!dp[i]) continue;
    int64_t use=0;
    int64_t index=i+size;
    while(use<amount){
      if(index>SIZE||dp[index]) break;
      dp[index]=1;
      index+=size;
      use++;
    }
  }
}

int main(){
  int64_t W;
  scanf("%I64d",&W);
  int64_t sum=0;
  for(int64_t i=1;i<=8;i++){
    scanf("%I64d",&cnt[i]);
    sum+=cnt[i]*i;
  }
  if(sum<=W){
    printf("%I64d\n",sum);
    return 0;
  }
  for(int i=8;i>=1;i--){
    hold[i]=std::min<int64_t>(W/i,cnt[i]);
    W-=i*hold[i];
    cnt[i]-=hold[i];
  }
  for(int i=3;i<=8;i++){
    int rev=std::min<int64_t>(i-3,hold[i]);
    hold[i]-=rev;
    cnt[i]+=rev;
    W+=i*rev;
  }
  dp[0]=1;
  for(int i=1;i<=8;i++){
    //printf("%d: %I64d %I64d\n",i,hold[i],cnt[i]);
    add(i,cnt[i]);
  }
  assert(W>=0&&W<=SIZE);
  while(!dp[W]) W--;
  for(int i=1;i<=8;i++){
    W+=i*hold[i];
  }
  printf("%I64d\n",W);
  return 0;
}