#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

int uf[200000];
int sz[200000];
std::set<int> roots;
int N;

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

void unite(int a,int b){
  a=find(a),b=find(b);
  if(a!=b){
    sz[a]+=sz[b];
    uf[b]=a;
    roots.erase(b);
  }
}

std::vector<int> edges[200000];

int main(){
  int M;
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N,0);
  std::fill(sz,sz+N,1);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    if(X>Y){
      std::swap(X,Y);
    }
    edges[Y].push_back(X);
  }
  for(int i=0;i<N;i++){
    std::map<int,int> cnt;
    for(int root:roots){
      cnt[root]=sz[root];
    }
    for(int other:edges[i]){
      cnt[find(other)]--;
    }
    for(auto pair:cnt){
      if(pair.second!=0){
	unite(i,pair.first);
      }
    }
    roots.insert(i);
  }
  std::vector<int> cmpts;
  for(int i=0;i<N;i++){
    if(i==find(i)){
      cmpts.push_back(sz[i]);
    }
  }
  std::sort(cmpts.begin(),cmpts.end());
  printf("%d\n",(int)cmpts.size());
  for(int i=0;i<cmpts.size();i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",cmpts[i]); 
  }
  printf("\n");
  return 0;
}