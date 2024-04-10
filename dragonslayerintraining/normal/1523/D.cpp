#include <cstdio>
#include <stdint.h>
#include <chrono>
#include <random>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

char str[64];
uint64_t sets[200005];
int N,M,P;

int subsum[1<<15];

uint64_t check(uint64_t mask){
  std::fill(subsum,subsum+(1<<P),0);
  for(int i=0;i<N;i++){
    int submask=0;
    int j=0;
    for(int k=0;k<M;k++){
      if((mask&(1ULL<<k))==0) continue;
      if(sets[i]&(1ULL<<k)){
	submask|=(1<<j);
      }
      j++;
    }
    subsum[submask]++;
  }
  for(int k=0;k<P;k++){
    for(int i=0;i<(1<<P);i++){
      if(i&(1<<k)) continue;
      subsum[i]+=subsum[i|(1<<k)];
    }
  }
  int best=0;
  for(int i=0;i<(1<<P);i++){
    if(subsum[i]>=(N+1)/2 && __builtin_popcount(i)>__builtin_popcount(best)){
      best=i;
    }
  }
  uint64_t decoded=0;
  int j=0;
  for(int k=0;k<M;k++){
    if((mask&(1ULL<<k))==0) continue;
    if(best&(1<<j)){
      decoded|=(1ULL<<k);
    }
    j++;
  }
  //fprintf(stderr,"best=%d\n",best);
  return decoded;
}

int main(){
  scanf("%d %d %d",&N,&M,&P);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    for(int j=0;j<M;j++){
      if(str[j]=='1'){
	sets[i]|=1ULL<<j;
      }
    }
  }
  std::uniform_int_distribution<int> distr(0,N-1);
  uint64_t best=0;
  //auto start=clock();
  //int iter=0;
  //while(clock()-start<2.0*CLOCKS_PER_SEC){
  for(int iter=0;iter<30;iter++){
    int i=distr(rng);
    uint64_t mask=check(sets[i]);
    if(__builtin_popcountll(mask)>__builtin_popcountll(best)){
      best=mask;
    }
  }
  for(int j=0;j<M;j++){
    if(best&(1ULL<<j)){
      printf("1");
    }else{
      printf("0");
    }
  }
  printf("\n");
  //fprintf(stderr,"%d iterations\n",iter);
}