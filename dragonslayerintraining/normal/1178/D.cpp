#include <cstdio>
#include <algorithm>
#include <cassert>

bool prime[2001];

int main(){
  std::fill(prime+2,prime+2001,true);
  for(int i=2;i<=2000;i++){
    if(prime[i]){
      for(int j=i*2;j<=2000;j+=i){
	prime[j]=false;
      }
    }
  }
  int N;
  scanf("%d",&N);
  int E=0;
  while(!prime[N+E]){
    E++;
  }
  assert(E<=N/2);
  printf("%d\n",N+E);
  for(int i=0;i<N;i++){
    printf("%d %d\n",i+1,(i+1)%N+1);
  }
  for(int i=0;i<E;i++){
    assert(i<N/2);
    printf("%d %d\n",i+1,(i+N/2)+1);
  }
  return 0;
}