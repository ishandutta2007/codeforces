#include <cstdio>
#include <map>

std::map<int,int> map;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    map[A]=i+1;
  }
  if(map.size()<K){
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  int k=0;
  for(auto it:map){
    if(k) printf(" ");
    printf("%d",it.second);
    if(++k==K) break;
  }
  printf("\n");
  return 0;
}