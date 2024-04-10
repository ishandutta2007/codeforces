#include <cstdio>
#include <vector>
#include <algorithm>

int deg[100000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    deg[A]++;
    deg[B]++;
  }
  int* maxdeg=std::max_element(deg,deg+N);
  if(*maxdeg>2){
    int big=0;
    for(int i=0;i<N;i++){
      big+=(deg[i]>2);
    }
    if(big>1){
      printf("No\n");
      return 0;
    }
  }
  std::vector<int> vs;
  for(int i=0;i<N;i++){
    if(i==(maxdeg-deg)) continue;
    if(deg[i]==1){
      vs.push_back(i);
    }
  }
  printf("Yes\n");
  printf("%d\n",(int)vs.size());
  for(int v:vs){
    printf("%d %d\n",int(maxdeg-deg)+1,v+1);
  }
  return 0;
}