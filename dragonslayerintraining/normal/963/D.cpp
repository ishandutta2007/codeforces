#include <cstdio>
#include <chrono>
#include <random>
#include <cassert>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <array>

const int INF=1e9+7;
const int MOD=1e9+7;
int BASE,IBASE;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void addmod(int& x,int64_t y){
  x=(x+y)%MOD;
}

int modpow(int base,int exp){
  int ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=1LL*ac*base%MOD;
    }
    base=1LL*base*base%MOD;
  }
  return ac;
}

int hash[100005];
int bpow[100005]={1};
int ibpow[100005]={1};
char str[100005];
int str_len=0;
char sub[100005];
int N;

int ans[100005];
std::vector<std::array<int,3> > queries[100005];

int main(){
  BASE=std::uniform_int_distribution<int>(256,MOD-1)(rng);
  IBASE=modpow(BASE,MOD-2);
  assert(1LL*BASE*IBASE%MOD==1);
  scanf("%s",str);
  str_len=strlen(str);
  scanf("%d",&N);
  for(int i=0;i<str_len;i++){
    assert(1LL*bpow[i]*ibpow[i]%MOD==1);
    bpow[i+1]=1LL*bpow[i]*BASE%MOD;
    ibpow[i+1]=1LL*ibpow[i]*IBASE%MOD;
  }
  for(int i=0;i<str_len;i++){
    hash[i+1]=(hash[i]+1LL*bpow[i]*str[i])%MOD;
  }
  for(int i=0;i<N;i++){
    int K;
    scanf("%d %s",&K,sub);
    int sub_len=strlen(sub);
    int H=0;
    for(int i=0;i<sub_len;i++){
      addmod(H,1LL*sub[i]*bpow[i]);
    }
    queries[sub_len].push_back({H,K,i});
  }
  for(int len=0;len<=str_len;len++){
    if(queries[len].empty()) continue;
    std::unordered_map<int,std::vector<int> > map;
    for(auto q:queries[len]){
      map[q[0]];
    }
    for(int i=0;i+len<=str_len;i++){
      int H=1LL*(hash[i+len]+MOD-hash[i])*ibpow[i]%MOD;
      if(map.count(H)){
	map[H].push_back(i);
      }
    }
    for(auto q:queries[len]){
      int H=q[0];
      int best=INF;
      //printf("query len=%d, H=%d id=%d\n",len,H,q[2]);
      for(int i=0;i+q[1]<=map[H].size();i++){
	int j=i+q[1]-1;
	//printf("candidate: %d..%d\n",map[H][i],map[H][j]);
	best=std::min(best,map[H][j]-map[H][i]+len);
      }
      ans[q[2]]=(best<INF)?best:-1;
    }
  }
  for(int i=0;i<N;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}