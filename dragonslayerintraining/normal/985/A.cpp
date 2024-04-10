#include <cstdio>
#include <algorithm>

int ps[50];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N/2;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  std::sort(ps,ps+N/2);
  int cost[2]={};
  for(int s=0;s<2;s++){
    for(int i=s;i<N;i+=2){
      cost[s]+=std::abs(ps[i/2]-i);
    }
  }
  printf("%d\n",std::min(cost[0],cost[1]));
  return 0;
}