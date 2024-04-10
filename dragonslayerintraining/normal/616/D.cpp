#include <cstdio>
#include <map>
#include <array>

int as[500005];

std::array<int,3> best;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::map<int,int> active;
  int j=0;
  for(int i=0;i<N;i++){
    active[as[i]]++;
    while(active.size()>K){
      if(--active[as[j]]==0){
	active.erase(as[j]);
      }
      j++;
    }
    best=std::max(best,{i-j+1,j+1,i+1});
  }
  printf("%d %d\n",best[1],best[2]);
}