#include <iostream>
#include <vector>

int uf[100000];
int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}
void merge(int a,int b){
  uf[find(a)]=find(b);
}

int N;

std::vector<std::pair<int,int> > edges[100000];
std::vector<int> queries[100000];
int road[100000];
int prefix[100001];


void dfs1(int node,int parent,int e){
  road[node]=e;
  for(int q:queries[node]){
    if(road[q]){
      prefix[road[q]]++;
      prefix[road[node]]++;
      prefix[road[find(q)]]-=2;
    }
  }
  for(std::pair<int,int> edge:edges[node]){
    int child=edge.first;
    if(child!=parent){
      dfs1(child,node,edge.second);
      merge(child,node);
    }
  }
}

void dfs2(int node,int parent){
  for(std::pair<int,int> edge:edges[node]){
    int child=edge.first;
    if(child!=parent){
      dfs2(child,node);
      prefix[road[node]]+=prefix[road[child]];
    }
  }
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  for(int i=0;i<N-1;i++){
    int U,V;
    std::cin>>U>>V;
    U--,V--;
    edges[U].emplace_back(V,i+1);
    edges[V].emplace_back(U,i+1);
  }
  int K;
  std::cin>>K;
  for(int i=0;i<K;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    queries[A].push_back(B);
    queries[B].push_back(A);
  }
  dfs1(0,0,N);
  dfs2(0,0);
  for(int i=1;i<N;i++){
    if(i>1){
      std::cout<<" ";
    }
    std::cout<<prefix[i];
  }
  std::cout<<std::endl;
  return 0;
}