#include <cstdio>
#include <algorithm>

int as[101][101];

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      scanf("%d",&as[j][i]);
    }
  }
  
  std::pair<int,int> total(0,0);
  for(int j=1;j<=M;j++){
    std::pair<int,int> best(-1,-1);
    for(int i=1;i<=N;i++){
      as[j][i]+=as[j][i-1];
    }
    for(int i=0;i<N;i++){
      best=std::max(best,
		    std::make_pair(as[j][std::min(N,i+K)]-as[j][i],
				   -as[j][i]));
    }
    total.first+=best.first;
    total.second+=best.second;
  }
  printf("%d %d\n",total.first,-total.second);
  return 0;
}