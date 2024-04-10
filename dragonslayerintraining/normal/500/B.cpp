#include <iostream>
#include <vector>
#include <algorithm>

int uf[300];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  uf[find(a)]=find(b);
}

int perm[300];

std::vector<int> sorted[300];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  for(int i=0;i<N;i++){
    std::cin>>perm[i];
  }
  for(int i=0;i<N;i++){
    std::string mat;
    std::cin>>mat;
    for(int j=0;j<N;j++){
      if(mat[j]=='1'){
	unite(i,j);
      }
    }
  }
  for(int i=0;i<N;i++){
    sorted[find(i)].push_back(perm[i]);
  }
  for(int i=0;i<N;i++){
    std::sort(sorted[i].begin(),sorted[i].end());
    std::reverse(sorted[i].begin(),sorted[i].end());
  }
  for(int i=0;i<N;i++){
    perm[i]=sorted[find(i)].back();
    sorted[find(i)].pop_back();
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<perm[i];
  }
  std::cout<<std::endl;
  
  return 0;
}