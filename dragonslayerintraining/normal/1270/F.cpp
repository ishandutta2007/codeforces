#include <cstdio>
#include <cstring>
#include <map>
#include <unordered_map>
#include <cassert>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//Adapted from https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//
const int BLK=2000;
const int BLK2=200000/BLK+2;

char str[200005];
int N;
int ps[200005];
int first[200005];

gp_hash_table<long long,int,custom_hash> table;

int main(){
  scanf("%s",str+1);
  N=strlen(str+1);
  for(int i=1;i<=N;i++){
    ps[i]=ps[i-1]+(str[i]=='1');
  }
  for(int i=N;i>=0;i--){
    first[ps[i]]=i;
  }
  long long ans=0;
  for(int j=1;j<=N;j++){
    for(int ones=1;ones<BLK;ones++){
      //ps[j]-ps[i]==ones
      int p_i=ps[j]-ones;
      if(p_i<0) break;
      int max=j-first[p_i];
      int min=j-(first[p_i+1]);
      ans+=max/ones-min/ones;
    }
  }
  for(int k=1;k<BLK2;k++){
    table.clear();
    int l=0;
    for(int j=1;j<=N;j++){
      //ps[j]-ps[i]>=BLK
      int p_i=ps[j]-BLK;//upper bound
      if(p_i<0) continue;
      while(l<first[p_i+1]){
	table[1LL*k*ps[l]-l]++;
	l++;
      }
      auto it=table.find(1LL*k*ps[j]-j);
      if(it!=table.end()){
	ans+=it->second;
      }
    }
  }
  
  printf("%lld\n",ans);
  exit(0);
}