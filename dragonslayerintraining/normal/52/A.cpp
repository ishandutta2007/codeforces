#include <cstdio>
#include <algorithm>

int cnts[3];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int ai;
    scanf("%d",&ai);
    cnts[ai-1]++;
  }
  printf("%d\n",(cnts[0]+cnts[1]+cnts[2])-*std::max_element(cnts,cnts+3));
  return 0;
}