#include <iostream>
#include <set>

int parent[10000];

int find(int a){
  return (parent[a]==a)?a:(parent[a]=find(parent[a]));
}

void merge(int a,int b){
  parent[find(a)]=find(b);
}

int main(){
  int N;
  std::cin>>N;
  
  for(int i=0;i<N;i++){
    parent[i]=i;
  }
  
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    merge(i,A-1);
  }
  std::set<int> uniq;
  for(int i=0;i<N;i++){
    uniq.insert(find(i));
  }
  std::cout<<uniq.size()<<std::endl;
  return 0;
}