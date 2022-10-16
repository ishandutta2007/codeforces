#include <cstdio>
#include <algorithm>
#include <stdint.h>

struct Creature{
  int64_t hp,dmg;
}cs[200000];

int main(){
  int N,A,B;
  scanf("%d %d %d",&N,&A,&B);
  B=std::min(B,N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
    scanf("%I64d %I64d",&cs[i].hp,&cs[i].dmg);
    sum+=cs[i].dmg;
  }
  std::sort(cs,cs+N,[](struct Creature a,struct Creature b){return a.hp-a.dmg>b.hp-b.dmg;});
  for(int i=0;i<B;i++){
    sum+=std::max<int64_t>(0,cs[i].hp-cs[i].dmg);
  }
  int64_t inc=0;
  for(int i=0;i<B;i++){
    inc=std::max<int64_t>(inc,cs[i].hp*(1LL<<A)-std::max<int64_t>(cs[i].hp,cs[i].dmg));
  }
  if(B){
    for(int i=B;i<N;i++){
      inc=std::max<int64_t>(inc,cs[i].hp*(1LL<<A)-cs[i].dmg-std::max<int64_t>(0,cs[B-1].hp-cs[B-1].dmg));
    }
  }
  printf("%I64d\n",sum+inc);
  return 0;
}