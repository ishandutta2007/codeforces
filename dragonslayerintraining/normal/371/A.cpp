#include <cstdio>
#include <algorithm>

int cnt[100];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    cnt[i%K]+=(X==2);
  }
  int total=0;
  for(int i=0;i<K;i++){
    total+=std::min(cnt[i],N/K-cnt[i]);
  }
  printf("%d\n",total);
  return 0;
}