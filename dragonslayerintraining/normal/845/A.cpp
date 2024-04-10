#include <cstdio>
#include <algorithm>

int as[100];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N*2;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N*2);
  if(as[N-1]==as[N]){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
  return 0;
}