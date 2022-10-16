#include <cstdio>
#include <set>
#include <algorithm>
#include <stdint.h>

int64_t sum[600000];
int64_t ndiv[1000001];
int64_t N;

void build(){
  for(int64_t i=N-1;i>0;i--){
    sum[i]=sum[i<<1]+sum[i<<1|1];
  }
}

void update(int64_t i,int64_t v){
  for(sum[i+=N]=v;i>1;i/=2){
    sum[i>>1]=sum[i]+sum[i^1];
  }
}

int64_t query(int64_t l,int64_t r){
  int64_t ac=0;
  l+=N,r+=N;
  while(l<r){
    if(l&1) ac+=sum[l++];
    if(r&1) ac+=sum[--r];
    l>>=1,r>>=1;
  }
  return ac;
}

int main(){
  for(int64_t i=1;i<=1000000;i++){
    for(int64_t j=i;j<=1000000;j+=i){
      ndiv[j]++;
    }
  }
  int64_t M;
  scanf("%I64d %I64d",&N,&M);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&sum[i+N]);
  }
  build();
  std::set<int64_t> big;
  for(int64_t i=0;i<N;i++){
    big.insert(i);
  }
  while(M-->0){
    int64_t T,L,R;
    scanf("%I64d %I64d %I64d",&T,&L,&R);
    L--;
    if(T==1){
      auto it=big.lower_bound(L);
      while(it!=big.end()&&*it<R){
	update(*it,ndiv[sum[*it+N]]);
	if(sum[*it+N]<=2){
	  it=big.erase(it);
	}else{
	  it++;
	}
      }
    }else{
      printf("%I64d\n",query(L,R));
    }
  }
  return 0;
}