#include <cstdio>
#include <vector>
#include <map>
#include <chrono>
#include <cstdlib>
#include <stdint.h>

uint64_t id[1000000];
uint64_t adj[1000000];

std::vector<std::pair<int,int> > elist;

int main(){
  srand(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    id[i]=((uint64_t)rand()*RAND_MAX+rand())*RAND_MAX+rand();
  }
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    adj[U]^=id[V];
    adj[V]^=id[U];
    elist.emplace_back(U,V);
  }
  std::map<uint64_t,int> cnt;
  for(int i=0;i<N;i++){
    cnt[adj[i]]++;
  }
  int64_t total=0;
  for(auto it:cnt){
    total+=it.second*int64_t(it.second-1)/2;
  }
  for(auto e:elist){
    int U=e.first,V=e.second;
    if((adj[U]^id[U])==(adj[V]^id[V])){
      total++;
    }
  }
  printf("%I64d\n",total);
  return 0;
}