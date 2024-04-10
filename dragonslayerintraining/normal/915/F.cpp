#include <cstdio>
#include <tuple>
#include <algorithm>
#include <stdint.h>

int64_t sum=0;

int as[1000000];
int uf[1000000];
int size[1000000];
std::vector<std::tuple<int,int,int> > edges;
int N;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  a=find(a);
  b=find(b);
  if(a==b){
    return;
  }
  if(size[a]<size[b]){
    std::swap(a,b);
  }
  size[a]+=size[b];
  uf[b]=a;
}

void calc(){
  for(auto& e:edges){
    std::get<0>(e)=std::max(as[std::get<1>(e)],as[std::get<2>(e)]);
  } 
  std::sort(edges.begin(),edges.end());

  std::iota(uf,uf+N,0);
  std::fill(size,size+N,1);
  for(auto e:edges){
    int weight=std::get<0>(e);
    int A=std::get<1>(e);
    int B=std::get<2>(e);
    sum+=(int64_t)size[find(A)]*size[find(B)]*weight;
    unite(A,B);
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges.emplace_back(0,X,Y);
  }
  calc();
  for(int i=0;i<N;i++){
    as[i]=-as[i];
  }
  calc();
  printf("%I64d\n",sum);
  return 0;
}