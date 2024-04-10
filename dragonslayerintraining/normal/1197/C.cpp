#include <cstdio>
#include <algorithm>
#include <vector>

int as[300005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int cost=as[N-1]-as[0];
  std::vector<int> segs;
  for(int i=1;i<N;i++){
    segs.push_back(as[i]-as[i-1]);
  }
  std::sort(segs.begin(),segs.end());
  std::reverse(segs.begin(),segs.end());
  for(int i=0;i<K-1;i++){
    cost-=segs[i];
  }
  printf("%d\n",cost);
}