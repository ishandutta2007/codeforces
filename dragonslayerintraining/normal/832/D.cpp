#include <iostream>
#include <vector>

int anc[20][100000];

std::vector<int> children[100000];

int depth[100000];

void dfs(int node,int dep){
  depth[node]=dep;
  for(int child:children[node]){
    dfs(child,dep+1);
  }
}

int lca(int a,int b){
  if(depth[a]<depth[b]){
    std::swap(a,b);
  }
  int diff=depth[a]-depth[b];
  for(int k=19;k>=0;k--){
    if(diff&(1<<k)){
      a=anc[k][a];
    }
  }
  if(a==b){
    return a;
  }
  for(int k=19;k>=0;k--){
    if(anc[k][a]!=anc[k][b]){
      a=anc[k][a];
      b=anc[k][b];
    }
  }
  return anc[0][a];
}

int main(){
  int N,Q;
  std::cin>>N>>Q;
  for(int i=1;i<N;i++){
    int P;
    std::cin>>P;
    P--;
    anc[0][i]=P;
    children[P].push_back(i);
  }
  dfs(0,0);
  for(int k=1;k<20;k++){
    for(int i=0;i<N;i++){
      anc[k][i]=anc[k-1][anc[k-1][i]];
    }
  }
  for(int i=0;i<Q;i++){
    int best=0;
    int A,B,C;
    std::cin>>A>>B>>C;
    A--,B--,C--;
    int lab=lca(A,B);
    int lac=lca(A,C);
    int lbc=lca(B,C);
    //std::cout<<"LCA("<<A<<","<<B<<")="<<lab<<std::endl;
    //std::cout<<"LCA("<<A<<","<<C<<")="<<lac<<std::endl;
    //std::cout<<"LCA("<<B<<","<<C<<")="<<lbc<<std::endl;
    int dab=depth[A]+depth[B]-2*depth[lab];
    int dac=depth[A]+depth[C]-2*depth[lac];
    int dbc=depth[B]+depth[C]-2*depth[lbc];
    //std::cout<<"DIST("<<A<<","<<B<<")="<<dab<<std::endl;
    //std::cout<<"DIST("<<A<<","<<C<<")="<<dac<<std::endl;
    //std::cout<<"DIST("<<B<<","<<C<<")="<<dbc<<std::endl;
    int total=depth[A]+depth[B]+depth[C]-depth[lab]-depth[lac]-depth[lbc];
    std::cout<<total-std::min(dab,std::min(dac,dbc))+1<<std::endl;
  }
  
  return 0;
}