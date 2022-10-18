#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <tuple>
#include <cstdlib>

const int64_t MOD=1e9+7;

int64_t modpow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=ac*base%MOD;
    }
    base=base*base%MOD;
  }
  return ac;
}

struct Hasher{
  std::vector<int64_t> cs;
  std::vector<int64_t> hs;
  std::vector<int64_t> pow,ipow;
  int64_t base,ibase;
  Hasher(std::vector<int64_t> cs,int64_t base):cs(cs),hs(cs.size()+1),base(base),pow(cs.size()+1),ipow(cs.size()+1){
    ibase=modpow(base,MOD-2);
    pow[0]=1;
    ipow[0]=1;
    for(int64_t i=1;i<=cs.size();i++){
      pow[i]=pow[i-1]*base%MOD;
      ipow[i]=ipow[i-1]*ibase%MOD;
    }
    for(int64_t i=0;i<cs.size();i++){
      hs[i+1]=(hs[i]+cs[i]*pow[i])%MOD;
    }
  }
  int64_t query(int64_t L,int64_t R){
    return ipow[L+1]*(hs[R]+MOD-hs[L])%MOD;
  }
};

char str[200005];

std::vector<struct Hasher> hashes[3];
std::vector<int64_t> cs[3][26];

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  scanf("%s",str);
  for(int k=0;k<1;k++){
    int64_t base=rand()%MOD;
    for(int64_t s=0;s<26;s++){
      cs[k][s].resize(N);
    }
    for(int64_t i=0;i<N;i++){
      cs[k][str[i]-'a'][i]=1;
    }
    for(int64_t s=0;s<26;s++){
      hashes[k].emplace_back(cs[k][s],base);
    }
  }
  for(int64_t i=0;i<M;i++){
    int64_t X,Y,L;
    scanf("%I64d %I64d %I64d",&X,&Y,&L);
    X--,Y--;
    std::vector<std::tuple<int64_t,int64_t,int64_t> > S,T;
    for(int64_t s=0;s<26;s++){
      S.emplace_back(hashes[0][s].query(X,X+L),0,0);//hashes[1][s].query(X,X+L),hashes[2][s].query(X,X+L));
      T.emplace_back(hashes[0][s].query(Y,Y+L),0,0);//hashes[1][s].query(Y,Y+L),hashes[2][s].query(Y,Y+L));
      /*
      printf("%d %d %d:%d %d %d\n",hashes[0][s].query(X,X+L),hashes[1][s].query(X,X+L),hashes[2][s].query(X,X+L),
	     hashes[0][s].query(Y,Y+L),hashes[1][s].query(Y,Y+L),hashes[2][s].query(Y,Y+L));
      */
    }
    std::sort(S.begin(),S.end());
    std::sort(T.begin(),T.end());
    if(S==T){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}