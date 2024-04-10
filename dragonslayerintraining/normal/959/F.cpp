#include <cstdio>
#include <stdint.h>
#include <vector>

int64_t MOD=1e9+7;

int as[100000];

std::vector<std::pair<int,int> > queries[100000];

int res[100000];

int basis[20];

int reduce(int x){
  for(int k=19;k>=0;k--){
    if(x&(1<<k)){
      x^=basis[k];
    }
  }
  return x;
}

int64_t cnt=1;

void add(int x){
  x=reduce(x);
  for(int k=19;k>=0;k--){
    if(x&(1<<k)){
      basis[k]=x;
      return;
    }
  }
  cnt=cnt*2%MOD;
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<Q;i++){
    int L,X;
    scanf("%d %d",&L,&X);
    L--;
    queries[L].emplace_back(X,i);
  }
  for(int i=0;i<N;i++){
    add(as[i]);
    for(std::pair<int,int> query:queries[i]){
      int q=query.first;
      int id=query.second;
      if(reduce(q)){
	res[id]=0;
      }else{
	res[id]=cnt;
      }
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",res[i]);
  }
  
  return 0;
}