#include <cstdio>
#include <vector>
#include <stdint.h>

int N,M;
int as[200000];
std::vector<int> edges[200000];
int sign[200000];

int begin[200000],end[200000];
int t=0;

int64_t ft[400000];

void add(int i,int v){
  for(i++;i<N*2;i+=(i&-i)){
    ft[i]+=v;
  }
}

int64_t query(int i){
  int64_t sum=0;
  for(i++;i>0;i-=(i&-i)){
    sum+=ft[i];
  }
  return sum;
}

void dfs1(int node,int parent,int sgn){
  begin[node]=t++;
  sign[node]=sgn;
  for(int child:edges[node]){
    if(child!=parent){
      dfs1(child,node,-sgn);
    }
  }
  end[node]=t++;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&(as[i]));
  }
  for(int i=1;i<N;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs1(0,0,1);
  for(int i=0;i<M;i++){
    int type;
    int X;
    scanf("%d %d",&type,&X);
    X--;
    switch(type){
    case 1:{
      int val;
      scanf("%d",&val);
      add(begin[X],val*sign[X]);
      add(end[X],-val*sign[X]);
      break;
    }
    case 2:{
      printf("%I64d\n",query(begin[X])*sign[X]+as[X]);
      break;
    }
    }
  }
  return 0;
}