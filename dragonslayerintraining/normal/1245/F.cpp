#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

std::vector<int> bits(int x){
  std::vector<int> res;
  for(;x;x/=2){
    res.push_back(x%2);
  }
  res.resize(30);
  std::reverse(res.begin(),res.end());
  return res;
}

std::vector<int> low,high;

long long dp[30][2][2][2][2];

long long count(int pos,bool qla,bool qra,bool qlb,bool qrb){
  if(pos==high.size()) return 1;
  long long& res=dp[pos][qla][qra][qlb][qrb];
  if(res!=-1) return res;
  res=0;
  for(int a=0;a<2;a++){
    for(int b=0;b<2;b++){
      if(a&&b) continue;
      if(!qla&&a<low[pos]) continue;
      if(!qlb&&b<low[pos]) continue;
      if(!qra&&a>high[pos]) continue;
      if(!qrb&&b>high[pos]) continue;
      res+=count(pos+1,
		 qla||a>low[pos],qra||a<high[pos],
		 qlb||b>low[pos],qrb||b<high[pos]);
    }
  }
  return res;
}

long long solve(int l,int r){
  low=bits(l);
  high=bits(r);
  return count(0,false,false,false,false);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int L,R;
    scanf("%d %d",&L,&R);
    memset(dp,-1,sizeof dp);
    printf("%I64d\n",solve(L,R));
  }
}