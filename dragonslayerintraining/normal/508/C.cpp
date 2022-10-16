#include <cstdio>
#include <set>
#include <cassert>

std::set<int,std::greater<int> > open;

std::set<int> lit;

int main(){
  int M,T,R;
  scanf("%d %d %d",&M,&T,&R);
  if(R>T){
    printf("-1\n");
    return 0;
  }
  for(int t=-T;t<=300;t++){
    open.insert(t);
  }
  int cost=0;
  for(int i=0;i<M;i++){
    int W;
    scanf("%d",&W);
    while(lit.size()&&*lit.begin()<=W){
      lit.erase(lit.begin());
    }
    while(lit.size()<R){
      assert(open.lower_bound(W)!=open.end());
      int t=*open.lower_bound(W);
      open.erase(t);
      lit.insert(t+T);
      cost++;
    }
  }
  printf("%d\n",cost);
  return 0;
}