#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

const int MOD=1e9+7;

int as[1000006];
int64_t size[1000006];

std::vector<int> children[1000006];

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

void dfs_size(int node){
  size[node]=as[node];
  for(int child:children[node]){
    dfs_size(child);
    size[node]+=size[child];
  }
}

int64_t dp[1000000];
int freq[1000000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=1;i<N;i++){
    int P;
    scanf("%d",&P);
    children[P-1].push_back(i);
  }
  dfs_size(0);
  std::map<int64_t,int> cps;
  for(int i=0;i<N;i++){
    cps[gcd(size[i],size[0])]++;
  }
  std::vector<int64_t> factors;
  for(auto it:cps){
    //printf("gcd=%d x%d\n",it.first,it.second);
    freq[factors.size()]=it.second;
    factors.push_back(it.first);
  }
  for(int i=0;i<factors.size();i++){
    for(int j=i+1;j<factors.size();j++){
      if(factors[j]%factors[i]==0){
	freq[i]+=freq[j];
      }
    }
    //printf("cd=%d x%d\n",factors[i],freq[i]);
  }
  dp[factors.size()-1]=1;
  for(int i=(int)factors.size()-2;i>=0;i--){
    if(size[0]!=freq[i]*factors[i]) continue;
    for(int j=i+1;j<factors.size();j++){
      if(factors[j]%factors[i]==0){
	dp[i]=(dp[i]+dp[j])%MOD;
      }
    }
  }
  printf("%I64d\n",std::accumulate(dp,dp+factors.size(),0LL)%MOD);
}