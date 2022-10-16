#include <iostream>
#include <algorithm>
#include <vector>

struct solver{
  int N,M;
  std::vector<std::pair<int,int> > edges;
  std::vector<std::vector<int> > conn;
  std::vector<int> deg;
  std::vector<int> uf;
  std::vector<int> data;
  int cycle;
  int find(int a){
    return (a==uf[a])?a:(uf[a]=find(uf[a]));
  }
  void merge(int a,int b){
    uf[find(a)]=find(b);
  }
  solver():cycle(-1){
    std::cin>>N>>M;
    conn.resize(N);
    deg.resize(N);
    uf.resize(N);
    data.resize(N);
    std::iota(uf.begin(),uf.end(),0);
    for(int i=0;i<M;i++){
      int A,B;
      std::cin>>A>>B;
      A--,B--;
      edges.emplace_back(A,B);
      conn[A].push_back(B);
      conn[B].push_back(A);
      if(find(A)==find(B)){
	cycle=A;
      }
      merge(A,B);
      deg[A]++;
      deg[B]++;
    }
  }
  int dfs_depth(int node,int parent){
    for(int child:conn[node]){
      if(child!=parent){
	return 1+dfs_depth(child,node);
      }
    }
    return 1;
  }
  void dfs_arith(int node,int parent,int ctr,int dec){
    if(ctr==0){
      return;
    }
    data[node]=ctr;
    for(int child:conn[node]){
      if(child!=parent){
	dfs_arith(child,node,ctr-dec,dec);
      }
    }
  }
  void solve(){
    if(cycle>=0){
      std::cout<<"YES"<<std::endl;
      for(int i=0;i<N;i++){
	if(i>0){
	  std::cout<<" ";
	}
	std::cout<<(find(i)==find(cycle));
      }
      std::cout<<std::endl;
      return;
    }
    std::fill(data.begin(),data.end(),0);
    for(int i=0;i<N;i++){
      data[find(i)]+=(deg[i]==1);
    }
    for(int i=0;i<N;i++){
      if(data[i]>=4){
	std::cout<<"YES"<<std::endl;
	for(int k=0;k<N;k++){
	  if(k>0){
	    std::cout<<" ";
	  }
	  std::cout<<((find(k)==i)?((deg[k]>1)?2:1):0);
	}
	std::cout<<std::endl;
	return;
      }
    }
    std::fill(data.begin(),data.end(),0);
    for(int i=0;i<N;i++){
      if(deg[i]==3){
	std::vector<std::pair<int,int> > branches;
	for(int other:conn[i]){
	  branches.emplace_back(1+dfs_depth(other,i),other);
	}
	std::sort(branches.begin(),branches.end());
	if(branches[0].first>=3){
	  data[i]=3;
	  dfs_arith(branches[0].second,i,2,1);
	  dfs_arith(branches[1].second,i,2,1);
	  dfs_arith(branches[2].second,i,2,1);
	}else if((branches[0].first==2)&&
		 (branches[1].first>=4)){
	  data[i]=4;
	  dfs_arith(branches[0].second,i,2,2);
	  dfs_arith(branches[1].second,i,3,1);
	  dfs_arith(branches[2].second,i,3,1);
	}else if((branches[0].first==2)&&
		 (branches[1].first==3)&&
		 (branches[2].first>=6)){
	  data[i]=6;
	  dfs_arith(branches[0].second,i,3,3);
	  dfs_arith(branches[1].second,i,4,2);
	  dfs_arith(branches[2].second,i,5,1);
	}else{
	  continue;
	}
	std::cout<<"YES"<<std::endl;
	for(int k=0;k<N;k++){
	  if(k>0){
	    std::cout<<" ";
	  }
	  std::cout<<data[k];
	}
	std::cout<<std::endl;
	return;
      }
    }
    std::cout<<"NO"<<std::endl;
  }
};
int main(){
  int T;
  std::cin>>T;
  while(T-->0){
    solver().solve();
  }
  return 0;
}