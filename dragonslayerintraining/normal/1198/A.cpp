#include <cstdio>
#include <algorithm>
#include <map>

int as[400005];

int main(){
  int N,I;
  scanf("%d %d",&N,&I);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  int k=30;
  while(k*N>I*8){
    k--;
  }
  std::map<int,int> active;
  int j=0;
  int best=0;
  for(int i=0;i<N;i++){
    active[as[i]]++;
    while(active.size()>(1LL<<k)){
      if(--active[as[j]]==0){
	active.erase(as[j]);
      }
      j++;
    }
    best=std::max(best,i-j+1);
  }
  printf("%d\n",N-best);
}