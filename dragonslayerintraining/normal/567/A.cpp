#include <cstdio>
#include <algorithm>

int xs[100000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  for(int i=0;i<N;i++){
    int min=2e9,max=std::max(xs[i]-xs[0],xs[N-1]-xs[i]);
    if(i>0) min=std::min(min,xs[i]-xs[i-1]);
    if(i<N-1) min=std::min(min,xs[i+1]-xs[i]);
    printf("%d %d\n",min,max);
  }
  return 0;
}