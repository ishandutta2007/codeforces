#include <iostream>
#include <set>
#include <algorithm>

int N,M;

int uf[200];
int know=0;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int merge(int a,int b){
  return uf[find(a)]=find(b);
}

int main(){
  std::cin>>N>>M;
  std::iota(uf,uf+N+M,0);
  for(int i=0;i<N;i++){
    int K;
    std::cin>>K;
    for(int k=0;k<K;k++){
      int A;
      std::cin>>A;
      A--;
      merge(i,N+A);
      know++;
    }
  }
  if(know==0){
    std::cout<<N<<std::endl;
    return 0;
  }
  std::set<int> components;
  for(int i=0;i<N;i++){
    components.insert(find(i));
  }
  std::cout<<components.size()-1<<std::endl;
  return 0;
}