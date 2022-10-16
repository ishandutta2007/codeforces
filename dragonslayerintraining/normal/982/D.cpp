#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

int size[100000];
int uf[100000];
int cmpts=0;
int bysize[100000];
int distinct=0;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void merge(int a,int b){
  a=find(a),b=find(b);
  if(a==b) return;
  if(--bysize[size[a]]==0) distinct--;
  if(--bysize[size[b]]==0) distinct--;
  
  size[b]+=size[a];
  uf[a]=b;
  cmpts--;
  if(bysize[size[b]]++==0) distinct++;
}

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,std::vector<int> > upd;
  int max=-1e9;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    upd[A].push_back(i);
    max=std::max(max,A);
  }
  std::iota(uf,uf+N,0);
  std::fill(size,size+N,0);
  cmpts=0;
  distinct=0;
  std::pair<int,int> best;
  for(auto pair:upd){
    for(int i:pair.second){
      assert(size[i]==0);
      size[i]=1;
      if(bysize[size[i]]++==0) distinct++;
      cmpts++;
      
      if(i>0&&size[i-1]>0) merge(i-1,i);
      if(i<N-1&&size[i+1]>0) merge(i,i+1);
    }
    if(distinct==1){
      best=std::max(best,std::make_pair(bysize[size[find(pair.second[0])]],-(pair.first+1)));
      //printf("#=%d\tSIZE: %d\tK*=%d\n",bysize[find(pair.second[0])],size[find(pair.second[0])],pair.first);
    }
  }
  printf("%d\n",-best.second);
  return 0;
}