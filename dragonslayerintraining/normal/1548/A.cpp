#include <cstdio>
#include <algorithm>

int ans=0;

//number of adjacent higher neighbors
int adj[200005];

void add(int x,int y,int v){
  if(x>y) std::swap(x,y);
  ans-=(adj[x]==0);
  adj[x]+=v;
  ans+=(adj[x]==0);
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  ans=N;
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    add(U,V,1);
  }
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T;
    scanf("%d",&T);
    if(T==1){
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      add(U,V,1);
    }else if(T==2){
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      add(U,V,-1);
    }else if(T==3){
      printf("%d\n",ans);
    }
  } 
}