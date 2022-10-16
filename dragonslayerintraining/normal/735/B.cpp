#include <cstdio>
#include <algorithm>
#include <stdint.h>

int as[100000];

int main(){
  int N,N1,N2;
  scanf("%d %d %d",&N,&N1,&N2);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(N1>N2) std::swap(N1,N2);
  std::sort(as,as+N);
  std::reverse(as,as+N);
  int64_t city1=0;
  for(int i=0;i<N1;i++){
    city1+=as[i];
  }
  int64_t city2=0;
  for(int i=N1;i<N1+N2;i++){
    city2+=as[i];
  }
  printf("%.10lf\n",double(city1)/N1+double(city2)/N2);
  return 0;
}