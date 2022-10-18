#include <cstdio>
#include <algorithm>

int as[1000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  printf("%d\n",as[(N-1)/2]);
  return 0;
}