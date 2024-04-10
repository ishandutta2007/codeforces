#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>

const int INF=1e9+7;

int64_t hs[100005];
int64_t cps[100005];

std::pair<int,int> dp[100005];
int N,D;

std::pair<int,int> st[200005];

void pull(int i){
  st[i]=std::max(st[i<<1],st[i<<1|1]);
}

void update(int i,std::pair<int,int> v){
  for(st[i+=N]=v;i>1;i>>=1){
    pull(i>>1);
  }
}

std::pair<int,int> query(int a,int b){
  std::pair<int,int> res(0,-1);
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) res=std::max(res,st[a++]);
    if(b&1) res=std::max(res,st[--b]);
  }
  return res;
}
  

int main(){
  scanf("%d %d",&N,&D);
  for(int i=0;i<N;i++){
    scanf("%I64d",&hs[i]);
  }
  for(int i=0;i<N;i++){
    update(i,{0,-1});
  }
  std::copy(hs,hs+N,cps);
  std::sort(cps,cps+N);
  for(int i=0;i<N;i++){
    dp[i]=std::max(query(0,std::upper_bound(cps,cps+N,hs[i]-D)-cps),
		   query(std::lower_bound(cps,cps+N,hs[i]+D)-cps,N));
    dp[i].first++;
    update(std::lower_bound(cps,cps+N,hs[i])-cps,{dp[i].first,i});
    //printf("dp[%d]: %d,%d\n",i,dp[i].first,dp[i].second);
  }
  std::vector<int> ans;
  for(int i=query(0,N).second;i!=-1;i=dp[i].second){
    ans.push_back(i);
  }
  std::reverse(ans.begin(),ans.end());
  printf("%d\n",(int)ans.size());
  for(int x:ans){
    printf("%d ",x+1);
  }
  return 0;
}