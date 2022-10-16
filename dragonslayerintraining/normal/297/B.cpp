#include <cstdio>
#include <algorithm>

int as[100005],bs[100005];

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<M;i++){
    scanf("%d",&bs[i]);
  }
  std::sort(as,as+N);
  std::sort(bs,bs+M);
  std::reverse(as,as+N);
  std::reverse(bs,bs+M);

  for(int i=0;i<std::max(N,M);i++){
    if(as[i]>bs[i]){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}