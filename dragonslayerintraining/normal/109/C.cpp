#include <iostream>
#include <vector>

bool islucky(int n){
  if(n==0){
    return false;
  }
  for(;n>0;n/=10){
    if((n%10!=4)&&(n%10!=7)){
      return false;
    }
  }
  return true;
}

std::vector<std::pair<int,bool> > edges[100000];
bool visited[100000];
int counts[100000];
int size[100000];
long long total=0;

void dfs1(int node,int parent){
  size[node]=1;
  counts[node]=0;
  for(int i=0;i<edges[node].size();i++){
    int child=edges[node][i].first;
    bool lucky=edges[node][i].second;
    if(child!=parent){
      dfs1(child,node);
      if(lucky){
	counts[node]+=size[child];
      }else{
	counts[node]+=counts[child];
      }
      size[node]+=size[child];
    }
  }
}

void dfs2(int node,int parent,int upper_counts){
  for(int i=0;i<edges[node].size();i++){
    int child=edges[node][i].first;
    bool lucky=edges[node][i].second;
    if(child!=parent){
      if(lucky){
	dfs2(child,node,size[0]-size[child]);
      }else{
	dfs2(child,node,upper_counts+counts[node]-counts[child]);
      }
    }
  }
  long long lucky_paths=counts[node]+upper_counts;
  total+=(lucky_paths)*(lucky_paths-1);
}

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    int U,V,W;
    std::cin>>U>>V>>W;
    U--,V--;
    edges[U].push_back(std::make_pair(V,islucky(W)));
    edges[V].push_back(std::make_pair(U,islucky(W)));
  }
  dfs1(0,0);
  dfs2(0,0,0);
  std::cout<<total<<std::endl;
  return 0;
}