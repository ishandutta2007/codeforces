#include <cstdio>
#include <algorithm>

int main(){
  int N;
  scanf("%d",&N);
  int min=1e9,max=0;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    min=std::min(min,A);
    max=std::max(max,A);
  }
  printf("%d\n",max-min+1-N);
  return 0;
}