#include <cstdio>
#include <map>
#include <stdint.h>
#include <algorithm>

const int64_t MOD=1e9+7;

int64_t pow2[500005]={1};
int64_t cs[500005];

int uf[500005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=1;i<=N;i++){
    pow2[i]=pow2[i-1]*2%MOD;
  }
  for(int i=0;i<N;i++){
    scanf("%I64d",&cs[i]);
  }
  std::iota(uf,uf+N,0);
  std::map<int64_t,std::vector<std::pair<int,int> > > edges;
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[cs[U]^cs[V]].emplace_back(U,V);
  }
  int64_t ans=((1LL<<K)-edges.size())%MOD*pow2[N]%MOD;
  for(auto pair:edges){
    int exp=N;
    for(auto e:pair.second){
      int A=find(e.first);
      int B=find(e.second);
      if(A!=B){
	exp--;
	uf[A]=B;
      }
    }
    for(auto e:pair.second){
      uf[e.first]=e.first;
      uf[e.second]=e.second;
    }
    ans=(ans+pow2[exp])%MOD;
  }
  printf("%I64d\n",ans);
  return 0;
}