#include <cstdio>
#include <algorithm>
#include <stdint.h>

int bs[100000];

int64_t cola=0;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cola+=A;
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  std::sort(bs,bs+N);
  std::reverse(bs,bs+N);
  if(cola<=bs[0]+bs[1]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}