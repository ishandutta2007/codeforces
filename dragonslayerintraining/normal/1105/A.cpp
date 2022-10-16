#include <cstdio>
#include <algorithm>

int as[105];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::pair<int,int> best(1e9+7,0);
  for(int v=1;v<=100;v++){
    int cost=0;
    for(int i=0;i<N;i++){
      cost+=std::max(0,std::abs(v-as[i])-1);
    }
    best=std::min(best,std::make_pair(cost,v));
  }
  printf("%d %d\n",best.second,best.first);
  return 0;
}