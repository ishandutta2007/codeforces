#include <cstdio>
#include <vector>
#include <algorithm>

int uf[100005];
int size[100005];
std::vector<std::pair<int,std::pair<int,int> > > edges;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    uf[i]=i;
  }
  for(int i=0;i<K;i++){
    int X;
    scanf("%d",&X);
    X--;
    size[X]=1;
  }
  for(int i=0;i<M;i++){
    int U,V,W;
    scanf("%d %d %d",&U,&V,&W);
    U--,V--;
    edges.emplace_back(W,std::make_pair(U,V));
  }
  std::sort(edges.begin(),edges.end());
  for(auto it:edges){
    int W=it.first;
    int U=it.second.first;
    int V=it.second.second;
    //printf("E %d=%d %d\n",U+1,V+1,W);
    U=find(U),V=find(V);
    if(U==V) continue;
    if(size[U]+size[V]==K){
      for(int i=0;i<K;i++){
	if(i) printf(" ");
	printf("%d",W);
      }
      printf("\n");
      return 0;
    }
    if(size[U]>size[V]) std::swap(U,V);
    uf[U]=V;
    size[V]+=size[U];
  }
  return 0;
}