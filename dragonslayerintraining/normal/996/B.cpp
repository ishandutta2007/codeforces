#include <cstdio>
#include <algorithm>

int as[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::pair<int,int> best(1e9,1e9);
  for(int i=0;i<N;i++){
    best=std::min(best,std::make_pair(std::max(0,(as[i]-i+N-1))/N,i+1));
  }
  printf("%d\n",best.second);
  return 0;
}