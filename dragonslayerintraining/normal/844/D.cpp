#include <cstdio>
#include <random>
#include <chrono>
#include <cstdlib>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

std::pair<int,int> query(int i){
  printf("? %d\n",i);
  fflush(stdout);
  int val,next;
  scanf("%d %d",&val,&next);
  if(val==-1&&next==-1) exit(0);
  return {val,next};
}
  
int main(){
  int N,S,X;
  scanf("%d %d %d",&N,&S,&X);
  std::uniform_int_distribution<int> distr(1,N);
  int V=-1;//lower bound on val[S]
  for(int it=0;it<1998;it++){
    auto res=query((it<1000)?distr(rng):S);
    if(res.first<X&&res.first>V){
      S=res.second;
      V=res.first;
    }
    if(S==-1){
      printf("! -1\n");
      return 0;
    }
  }
  printf("! %d\n",query(S).first);
}