#include <iostream>
#include <set>

int uf[50];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  uf[find(a)]=find(b);
}

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  for(int i=0;i<M;i++){
    int X,Y;
    std::cin>>X>>Y;
    X--,Y--;
    unite(X,Y);
  }
  std::set<int> components;
  for(int i=0;i<N;i++){
    components.insert(find(i));
  }
  std::cout<<(1LL<<(N-components.size()))<<std::endl;
  return 0;
}