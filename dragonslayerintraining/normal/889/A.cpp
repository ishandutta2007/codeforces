#include <cstdio>
#include <set>

std::set<int> set;

int main(){
  int N;
  scanf("%d",&N);
  set.insert(0);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    set.insert(A);    
  }
  printf("%d\n",int(N+1-set.size()));
  return 0;
}