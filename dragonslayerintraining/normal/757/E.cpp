#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

const int64_t LIM=1000050;
const int64_t MOD=1e9+7;

std::vector<int64_t> exps[LIM+1];
int64_t factorial[LIM+1];
int64_t inverse[LIM+1];
int64_t inversefactorial[LIM+1];

int64_t combo(int64_t a,int64_t b){
  return ((a<0)||(b<0))?0:(factorial[a+b]*inversefactorial[a]%MOD*inversefactorial[b]%MOD);
}

int main(){
  for(int64_t i=2;i<=LIM;i++){
    if(exps[i].empty()){
      //i is prime
      for(int64_t k=i;k<=LIM;k+=i){
	exps[k].push_back(1);
      }
      for(int64_t p=i*i;p<=LIM;p*=i){
	for(int64_t k=p;k<=LIM;k+=p){
	  exps[k].back()++;
	}
      }
    }
  }
  inverse[1]=1;
  for(int64_t i=2;i<=LIM;i++){
    inverse[i]=(MOD-MOD/i)*inverse[MOD%i]%MOD;
  }
  factorial[0]=1;
  inversefactorial[0]=1;
  for(int64_t i=1;i<=LIM;i++){
    factorial[i]=factorial[i-1]*i%MOD;
    inversefactorial[i]=inversefactorial[i-1]*inverse[i]%MOD;
  }
  int Q;
  scanf("%d",&Q);
  for(int64_t i=0;i<Q;i++){
    int R,N;
    scanf("%d %d",&R,&N);
    int64_t prod=1;
    for(int64_t e:exps[N]){
      prod=prod*(2*combo(e,R)-combo(e,R-1)+MOD)%MOD;
    }
    printf("%d\n",static_cast<int>(prod));
  }
  return 0;
}