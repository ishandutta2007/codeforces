#include <cstdio>
#include <vector>
#include <stdint.h>

std::vector<int> hate[100005];
std::vector<int> sub[100005];//less pay and hate

int64_t danger=0;

void add(int x,int sgn=1){
  danger+=sgn*(int64_t)(sub[x].size()*(hate[x].size()-sub[x].size()));
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    hate[A].push_back(B);
    hate[B].push_back(A);
  }
  for(int i=0;i<N;i++){
    for(int j:hate[i]){
      if(j>i){
	sub[i].push_back(j);
      }
    }
  }
  for(int i=0;i<N;i++){
    add(i);
  }
  printf("%I64d\n",danger);
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int U;
    scanf("%d",&U);
    U--;
    for(int V:sub[U]){
      add(V,-1);
      sub[V].push_back(U);
      add(V);
    }
    add(U,-1);
    sub[U].clear();
    add(U);
    printf("%I64d\n",danger);
  }
}