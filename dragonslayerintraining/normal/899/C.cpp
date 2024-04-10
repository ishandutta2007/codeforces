#include <cstdio>
#include <vector>

std::vector<int> first;

int main(){
  int N;
  for(scanf("%d",&N);N>=4;N-=4){
    first.push_back(N);
    first.push_back(N-3);
  }
  int diff=0;
  switch(N){
  case 0:diff=0;break;
  case 1:diff=1;break;
  case 2:diff=1;first.push_back(1);break;
  case 3:diff=0;first.push_back(3);break;
  }
  printf("%d\n",diff);
  printf("%d",(int)first.size());
  for(int v:first){
    printf(" %d",v);
  }
  printf("\n");
  return 0;
}