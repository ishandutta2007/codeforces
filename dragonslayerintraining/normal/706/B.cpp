#include <cstdio>
#include <algorithm>

int xs[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  std::sort(xs,xs+N);
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int M;
    scanf("%d",&M);
    printf("%d\n",(int)(std::upper_bound(xs,xs+N,M)-xs));
  }
  return 0;
}