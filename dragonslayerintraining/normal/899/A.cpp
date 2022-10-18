#include <stdio.h>
#include <algorithm>

int cnt[3];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    cnt[X]++;
  }
  int total=0;
  total+=std::min(cnt[1],cnt[2]);
  cnt[1]-=std::min(cnt[1],cnt[2]);
  total+=cnt[1]/3;
  printf("%d\n",total);
  return 0;
}