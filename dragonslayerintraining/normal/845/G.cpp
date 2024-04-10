#include <cstdio>
#include <vector>


std::vector<std::pair<int,int> > edges[100005];

int label[100005];

int basis[30];

int cancel(int x){
  for(int k=30-1;k>=0;k--){
    if((basis[k]^x)<x){
      x^=basis[k];
    }
  }
  return x;
}

void add(int x){
  x=cancel(x);
  for(int k=30-1;k>=0;k--){
    if((x>>k)&1){
      basis[k]=x;
      return;
    }
  }
}

void dfs(int node,int val){
  label[node]=val;
  for(auto pair:edges[node]){
    int child=pair.first;
    if(label[child]==-1){
      dfs(child,val^pair.second);
    }else{
      add(label[node]^label[child]^pair.second);
    }
  }
}


int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int X,Y,W;
    scanf("%d %d %d",&X,&Y,&W);
    X--,Y--;
    edges[X].emplace_back(Y,W);
    edges[Y].emplace_back(X,W);
  }
  std::fill(label,label+N,-1);
  dfs(0,0);
  printf("%d\n",cancel(label[N-1]));
  return 0;
}