#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

int uf[200005];
std::map<int,std::vector<std::pair<int,int> > > edges;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  for(int i=0;i<M;i++){
    int U,V,W;
    scanf("%d %d %d",&U,&V,&W);
    edges[W].push_back(std::make_pair(U,V));
  }
  int count=0;
  for(auto layer:edges){
    std::vector<std::pair<int,int> > good;
    for(auto it:layer.second){
      if(find(it.first)!=find(it.second)){
	good.push_back(it);
      }
    }
    for(auto it:good){
      if(find(it.first)!=find(it.second)){
	uf[find(it.first)]=find(it.second);
      }else{
	count++;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}