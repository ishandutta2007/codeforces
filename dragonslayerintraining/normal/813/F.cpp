#include <iostream>
#include <map>
#include <vector>
#include <tuple>

bool dfs(int node,int c,std::vector<int>& color,
	 const std::vector<std::vector<int> >& adj){
  if(color[node]!=-1){
    return color[node]!=c;
  }
  color[node]=c;
  for(int other:adj[node]){
    if(dfs(other,c^1,color,adj)){
      return true;
    }
  }
  if(dfs(node^1,c^1,color,adj)){
    return true;
  }
  return false;
}

void solve(int L,int R,int N,std::vector<std::tuple<int,int,int,int> > edges){
  /*
    std::cout<<"SOLVE("<<L<<","<<R<<",#="<<N<<"):"<<std::endl;
    for(auto e:edges){
    std::cout<<std::get<0>(e)<<" "<<std::get<1>(e)<<" "<<std::get<2>(e)<<" "<<std::get<3>(e)<<std::endl;
    }
  */
  std::vector<int> prune(N>>1,0);
  for(auto e:edges){
    prune[std::get<0>(e)>>1]++;
    prune[std::get<1>(e)>>1]++;
  }
  int prune_max=0;
  for(int i=0;i<(N>>1);i++){
    if(prune[i]!=0){
      prune[i]=prune_max++;
    }
  }
  N=prune_max<<1;
  for(auto& e:edges){
    std::get<0>(e)=prune[std::get<0>(e)>>1]<<1|(std::get<0>(e)&1);
    std::get<1>(e)=prune[std::get<1>(e)>>1]<<1|(std::get<1>(e)&1);
  }
  /*
  for(int i=0;i<N;i+=2){
    edges.emplace_back(i,i+1,L,R);
  }
  */
  std::vector<std::vector<int> > adj(N);
  for(auto e:edges){
    if(std::get<2>(e)<=L&&std::get<3>(e)>=R){
      adj[std::get<0>(e)].push_back(std::get<1>(e));
      adj[std::get<1>(e)].push_back(std::get<0>(e));
      //std::cout<<"COVER("<<std::get<0>(e)<<","<<std::get<1>(e)<<")"<<std::endl;
    }
  }
  std::vector<int> color(N,-1);
  int color_max=0;
  for(int i=0;i<N;i++){
    if(color[i]==-1){
      if(dfs(i,color_max,color,adj)){
	for(int i=L;i<R;i++){
	  std::cout<<"NO"<<std::endl;
	}
	return;
      }
      color_max+=2;
    }
  }
  /*
  for(int i=0;i<N;i++){
    std::cout<<"COLOR("<<i<<")="<<color[i]<<std::endl;
  }
  */
  if(R-L==1){
    std::cout<<"YES"<<std::endl;
  }else{
    int M=(L+R)/2;
    std::vector<std::tuple<int,int,int,int> > left,right;
    for(auto e:edges){
      if(std::get<2>(e)>L||std::get<3>(e)<R){
	if(std::get<2>(e)<M){
	  left.emplace_back(color[std::get<0>(e)],
			    color[std::get<1>(e)],
			    std::get<2>(e),std::get<3>(e));
	}
	if(std::get<3>(e)>M){
	  right.emplace_back(color[std::get<0>(e)],
			     color[std::get<1>(e)],
			     std::get<2>(e),std::get<3>(e));
	}
      }
    }
    /*
    for(int i=0;i<color_max;i+=2){
      left.emplace_back(i,i+1,L,R);
      right.emplace_back(i,i+1,L,R);
    }
    */
    solve(L,M,color_max,left);
    solve(M,R,color_max,right);
  }
}

int main(){
  int N,Q;
  std::cin>>N>>Q;
  std::vector<std::tuple<int,int,int,int> > edges;
  std::map<std::pair<int,int>,int> active;
  for(int i=0;i<Q;i++){
    int X,Y;
    std::cin>>X>>Y;
    X--,Y--;
    if(X>Y) std::swap(X,Y);
    std::pair<int,int> E(X,Y);
    if(active.count(E)){
      std::get<3>(edges[active[E]])=i;
      active.erase(E);
    }else{
      active[E]=edges.size();
      edges.emplace_back(X*2,Y*2,i,Q);
    }
  }
  /*
  for(auto e:edges){
    std::cout<<std::get<0>(e)<<" "<<std::get<1>(e)<<" "<<std::get<2>(e)<<" "<<std::get<3>(e)<<std::endl;
  }
  */
  solve(0,Q,N*2,edges);
  return 0;
}