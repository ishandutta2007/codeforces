#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

struct spider{
  std::vector<std::vector<int> > graph;
  std::vector<int> height;
  int diameter;
  void dfs1(int node,int parent){
    height[node]=0;
    for(int i=0;i<graph[node].size();i++){
      int child=graph[node][i];
      if(child==parent){
	graph[node].erase(graph[node].begin()+i);
	break;
      }
    }
    for(int child:graph[node]){
      dfs1(child,node);
      height[node]=std::max(height[node],height[child]+1);
    }
  }
  int invertmax(const std::vector<int>& children,std::vector<int>& ret,int L,int R){
    if(R-L==1){
      return height[children[L]];
    }
    int M=(L+R)/2;
    int Lmax=invertmax(children,ret,L,M);
    int Rmax=invertmax(children,ret,M,R);
    for(int i=L;i<M;i++){
      ret[i]=std::max(ret[i],Rmax);
    }
    for(int i=M;i<R;i++){
      ret[i]=std::max(ret[i],Lmax);
    }
    return std::max(Lmax,Rmax);
  }
  void dfs2(int node,int parent,int upper){
    diameter=std::max(diameter,height[node]+upper);
    std::vector<int> v(graph[node].size());
    std::fill(v.begin(),v.end(),-1e9);
    if(v.size()>0){
      invertmax(graph[node],v,0,graph[node].size());
    }
    for(int i=0;i<graph[node].size();i++){
      int child=graph[node][i];
      int new_upper=std::max(upper+1,v[i]+2);
      dfs2(child,node,new_upper);
    }
    
  }
  spider():diameter(0){
    int N;
    fin>>N;
    graph.resize(N);
    height.resize(N);
    for(int i=1;i<N;i++){
      int A,B;
      fin>>A>>B;
      A--,B--;
      graph[A].push_back(B);
      graph[B].push_back(A);
    }
    dfs1(0,0);
    dfs2(0,0,0);
  }
};

int main(){
  int N;
  fin>>N;
  int total=0;
  for(int i=0;i<N;i++){
    struct spider s;
    total+=s.diameter;
  }
  fout<<total<<std::endl;
  return 0;
}