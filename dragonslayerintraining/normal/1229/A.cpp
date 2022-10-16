#include <cstdio>
#include <stdint.h>
#include <algorithm>

int N;
int64_t as[7001];
int bs[7001];

int out[7001];
int use[7001];
int use_cnt=0;

bool dom(int i,int j){
  return as[i]&~as[j];
}

bool improve(){
  for(int i=0;i<N;i++){
    if(!use[i]) continue;
    if(out[i]==use_cnt-1){
      for(int j=0;j<N;j++){
	out[j]-=dom(j,i);
      }
      use[i]=false;
      use_cnt--;
      return true;
    }
  }
  return false;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  std::fill(use,use+N,true);
  use_cnt=N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      out[i]+=dom(i,j);
    }
  }
  while(improve());
  if(use_cnt<2){
    printf("0\n");
  }else{
    int64_t sum=0;
    for(int i=0;i<N;i++){
      sum+=use[i]*bs[i];
    }
    printf("%I64d\n",sum);
  }
}