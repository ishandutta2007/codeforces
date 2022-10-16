#include <cstdio>
#include <algorithm>

int hs[150000];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&hs[i]);
  }
  std::pair<int,int> best(1e9,0);
  int sum=0;
  for(int i=0;i<K;i++){
    sum+=hs[i];
  }
  for(int i=0;i<N-K;i++){
    best=std::min(best,std::make_pair(sum,i));
    sum+=hs[i+K]-hs[i];
  }
  best=std::min(best,std::make_pair(sum,N-K));
  printf("%d\n",best.second+1);
  return 0;
}