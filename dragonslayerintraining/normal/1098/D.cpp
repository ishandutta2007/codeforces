#include <cstdio>
#include <stdint.h>
#include <set>

struct Block{
  std::multiset<int64_t> eels;
  int64_t min,sum;
  Block():sum(0){
  }
  void recalc(){
    if(eels.size()){
      min=*eels.begin();
    }
  }
  void insert(int64_t x){
    eels.insert(x);
    sum+=x;
    recalc();
  }
  void erase(int64_t x){
    eels.erase(eels.find(x));
    sum-=x;
    recalc();
  }
}blocks[32];
int64_t size=0;

int main(){
  int64_t Q;
  scanf("%I64d",&Q);
  for(int64_t i=0;i<Q;i++){
    char T;
    int64_t X;
    scanf(" %c %I64d",&T,&X);
    int64_t k=0;
    while((1<<k)<X) k++;
    if(T=='-'){
      blocks[k].erase(X);
      size--;
    }else{
      blocks[k].insert(X);
      size++;
    }
    int64_t sum=0;
    int64_t ans=size;
    for(int64_t k=0;k<32;k++){
      if(blocks[k].eels.size()&&sum*2<blocks[k].min){
	ans--;
      }
      sum+=blocks[k].sum;
    }
    printf("%I64d\n",ans);
  }
  return 0;
}