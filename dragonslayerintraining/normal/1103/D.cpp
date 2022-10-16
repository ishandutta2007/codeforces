#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stdint.h>

const int64_t INF=1e12+7;

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int64_t primes[15];
int primes_size=0;
int64_t as[1000005];
int64_t dp[12][1<<11];
int64_t reach[1<<11];
int64_t factor[11];
std::vector<int> best[1<<11];
std::vector<int> rbest[1000005];
std::pair<int64_t,int64_t> bs[1000005];

int main(){
  int64_t N,K;
  scanf("%I64d %I64d",&N,&K);
  int64_t G=0;
  char c=getchar();
  for(int i=0;i<N;i++){
    scanf("%I64d",&as[i]);
    G=gcd(G,as[i]);
  }
  for(int p=2;p<1000000;p++){
    if(G%p==0){
      while(G%p==0){
	G/=p;
      }
      primes[primes_size++]=p;
    }
  }
  if(G>1){
    primes[primes_size++]=G;
  }
  for(int i=0;i<N;i++){
    int64_t use=1;
    for(int pi=0;pi<primes_size;pi++){
      int64_t p=primes[pi];
      while(as[i]%p==0){
	as[i]/=p;
	use*=p;
      }
    }
    as[i]=use;
  }
  for(int i=0;i<N;i++){
    bs[i].first=as[i];
    scanf("%I64d",&bs[i].second);
  }
  std::sort(bs,bs+N);
  {
    int j=0;
    int cnt=0;
    for(int i=0;i<N;i++){
      if(i>0&&bs[i].first!=bs[i-1].first){
	cnt=1;
      }else{
	cnt++;
      }
      if(cnt<=primes_size){
	bs[j++]=bs[i];
      }
    }
    N=j;
  }
  for(int i=0;i<N;i++){
    if(i==0||bs[i].first!=bs[i-1].first){
      int64_t A=bs[i].first;
      for(int pi=0;pi<primes_size;pi++){
	factor[pi]=1;
	while(A%primes[pi]==0){
	  A/=primes[pi];
	  factor[pi]*=primes[pi];
	}
      }
      reach[0]=1;
      for(int pi=0;pi<primes_size;pi++){
	for(int mask=0;mask<(1<<pi);mask++){
	  reach[mask|(1<<pi)]=reach[mask]*factor[pi];
	}
      }
    }
    for(int mask=1;mask<(1<<primes_size);mask++){
      if(reach[mask]<=K){
	best[mask].push_back(i);
      }
    }
  }
  for(int mask=1;mask<(1<<primes_size);mask++){
    std::sort(best[mask].begin(),best[mask].end(),[](int i,int j){return bs[i].second<bs[j].second;});
    if(best[mask].size()>primes_size){
      best[mask].resize(primes_size);
    }
    for(int i:best[mask]){
      rbest[i].push_back(mask);
    }
    std::vector<int>().swap(best[mask]);
  }
  for(int pi=0;pi<=primes_size;pi++){
    std::fill(dp[pi],dp[pi]+(1<<primes_size),INF);
  }
  dp[0][0]=0;
  for(int i=0;i<N;i++){
    /*
    for(int64_t mask=0;mask<(1<<primes_size);mask++){
      reach[mask]=(reach[mask]<=K);
      //printf("Judge %I64d can reach mask %I64d?: %I64d\n",it.first,mask,reach[mask]);
    }
    */
    //printf("Judge: A=%I64d E=%I64d\n",it.first,E);
    int64_t E=bs[i].second;
    for(int j=primes_size;j>0;j--){
      for(int mask=0;mask<(1<<primes_size);mask++){
	for(int sub:rbest[i]){
	  if((sub&mask)!=sub) continue;
	  int64_t tmp=dp[j-1][mask^sub]+E;
	  if(dp[j][mask]>tmp) dp[j][mask]=tmp;
	}
      }
    }
  }
  int64_t best=INF;
  for(int i=0;i<=primes_size;i++){
    //printf("Candidate: %I64d*%I64d\n",i,dp[i][(1<<primes_size)-1]);
    if(dp[i][(1<<primes_size)-1]<INF){
      best=std::min(best,dp[i][(1<<primes_size)-1]*i);
    }
  }
  printf("%I64d\n",best==INF?-1:best);
  return 0;
}