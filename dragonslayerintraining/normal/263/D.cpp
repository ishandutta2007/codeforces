#include <iostream>
#include <cstdlib>
#include <vector>


std::vector<int> edges[100000];
int depth[100000];
int K;

std::vector<int> stack;

//leaf of DFS tree will find a cycle
void dfs(int node,int parent){
  if(depth[node]>0){
    //visited
    return;
  }
  stack.push_back(node);
  depth[node]=depth[parent]+1;//depth[0]=1
  for(int child:edges[node]){
    if(child!=parent){
      dfs(child,node);
      if(depth[node]-depth[child]+1>=K+1){
	int len=depth[node]-depth[child]+1;
	std::cout<<len<<std::endl;
	for(int i=0;i<len;i++){
	  if(i>0){
	    std::cout<<" ";
	  }
	  std::cout<<stack.back()+1;
	  stack.pop_back();
	}
	std::cout<<std::endl;
	exit(0);
      }
    }
  }
  stack.pop_back();
}

int main(){
  int N,M;
  std::cin>>N>>M>>K;
  for(int i=0;i<M;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  dfs(0,0);
  return 0;
}