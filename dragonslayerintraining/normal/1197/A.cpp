#include <cstdio>
#include <algorithm>

int as[100005];

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&as[i]);
    }
    std::sort(as,as+N);
    printf("%d\n",std::min(N-2,as[N-2]-1));
  }
}