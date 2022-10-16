#include <cstdio>
#include <algorithm>

int as[100001];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  int score=0;
  for(int i=1;i<=N;i++){
    int T;
    scanf("%d",&T);
    if(T){
      score+=as[i];
      as[i]=0;
    }
  }
  for(int i=1;i<=N;i++){
    as[i]+=as[i-1];
  }
  int best=0;
  for(int i=K;i<=N;i++){
    best=std::max(best,as[i]-as[i-K]);
  }
  printf("%d\n",best+score);
  return 0;
}