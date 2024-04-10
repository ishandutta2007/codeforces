#include <cstdio>
#include <vector>
#include <stdint.h>
#include <algorithm>

int deg[1000005];
int loop[1000005];
int loops=0;

int uf[1000005];

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    if(U!=V){
      deg[U]++,deg[V]++;
    }else{
      loop[U]=1;
      loops++;
    }
    uf[find(U)]=find(V);
  }
  int root;
  for(int i=0;i<N;i++){
    if(deg[i]){
      root=find(i);
      break;
    }
  }
  int64_t ans=1LL*loops*(loops-1)/2+1LL*loops*(M-loops);
  for(int i=0;i<N;i++){
    ans+=1LL*deg[i]*(deg[i]-1)/2;
    if((deg[i]+loop[i])&&find(i)!=find(root)){
      printf("0\n");
      return 0;
    }
  }
  printf("%I64d\n",ans);
  return 0;
}