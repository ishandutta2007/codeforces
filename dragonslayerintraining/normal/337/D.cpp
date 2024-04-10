#include <iostream>
#include <vector>
#include <algorithm>

int N,M,D;

std::vector<int> children[100000];
bool inrange[100000];
int sublimit[100000];
int superlimit_[100000];

int validcnt=0;

void dfs1(int node,int parent){
  std::vector<int>::iterator parent_it=std::find(children[node].begin(),children[node].end(),parent);
  if(parent_it!=children[node].end()){
    children[node].erase(parent_it);
  }
  sublimit[node]=inrange[node]?D:1e9;
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs1(child,node);
    sublimit[node]=std::min(sublimit[node],sublimit[child]-1);
  }
}

int invertmin(int node,std::vector<int>& v,
	      int L,int R){
  if(R-L==1){
    return sublimit[children[node][L]];
  }
  int M=(L+R)/2;
  int Lmin=invertmin(node,v,L,M);
  int Rmin=invertmin(node,v,M,R);
  for(int i=L;i<M;i++){
    v[i]=std::min(v[i],Rmin);
  }
  for(int i=M;i<R;i++){
    v[i]=std::min(v[i],Lmin);
  }
  return std::min(Lmin,Rmin);
}

void dfs2(int node,int parent,int superlimit){
  std::vector<int> v;
  v.resize(children[node].size());
  std::fill(v.begin(),v.end(),1e9);
  if(v.size()){
    invertmin(node,v,0,v.size());
  }
  if(inrange[node]){
    superlimit=std::min(superlimit,D);
  }
  if((superlimit>=0)&&(sublimit[node]>=0)){
    validcnt++;
  }
  superlimit_[node]=superlimit;
  for(int i=0;i<children[node].size();i++){
    int child=children[node][i];
    dfs2(child,node,std::min(superlimit-1,v[i]-2));
  }
}

int main(){
  std::cin>>N>>M>>D;
  for(int i=0;i<M;i++){
    int P;
    std::cin>>P;
    P--;
    inrange[P]=true;
  }
  for(int i=1;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    children[A].push_back(B);
    children[B].push_back(A);
  }
  dfs1(0,0);
  dfs2(0,0,1e9);
  std::cout<<validcnt<<std::endl;
  return 0;
}