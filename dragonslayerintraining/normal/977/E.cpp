#include <cstdio>
#include <algorithm>
#include <vector>

int uf[200000];
bool bad[200000];
int deg[200000];

std::vector<std::pair<int,int> > edges;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges.emplace_back(U,V);
    deg[U]++,deg[V]++;
  }
  for(auto e:edges){
    uf[find(e.first)]=find(e.second);
  }
  for(int i=0;i<N;i++){
    if(deg[i]!=2){
      bad[find(i)]=true;
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(i==find(i)&&!bad[i]){
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}