#include <cstdio>
#include <vector>
#include <cstdlib>
#include <stdint.h>

int N,K;

uint64_t op[11];
uint64_t first[11];
uint64_t used;

void check(int i,uint64_t mask){
  if(i==K){
    uint64_t inv=(1LL<<N)-1-mask;
    if(inv&(inv+1)){
      printf("REJECTED\n");
      exit(0);
    }
    return;
  }
  int min=__builtin_popcountll(mask&op[i]);
  int max=min+first[i];
  mask&=~op[i];
  for(uint64_t add=op[i];add;add&=(add-1)){
    if(__builtin_popcountll(add)>=min&&__builtin_popcountll(add)<=max){
      check(i+1,mask|add);
    }
  }
  if(min==0){
    check(i+1,mask);
  }
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++){
    int Q;
    scanf("%d",&Q);
    while(Q--){
      int J;
      scanf("%d",&J);
      J--;
      op[i]|=(1LL<<J);
    }
    first[i]=__builtin_popcountll(op[i]&~used);
    used|=op[i];
  }
  if(N>1&&(used!=((1LL<<N)-1))){
    printf("REJECTED\n");
    exit(0);
  }
  check(0,0);
  printf("ACCEPTED\n");
}