#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>

const int INF=1e9+7;
const int MOD=1e9+7;

int as[200005];
int bs[200005];
int xs[400005];

std::vector<int> left[400005];

struct MinCnt{
  int min,cnt;
  MinCnt():min(INF),cnt(0){
  }
  MinCnt(int min,int cnt):min(min),cnt(cnt){
  }
  MinCnt shift(int x)const{
    return MinCnt(min+x,cnt);
  }
};
int K;

MinCnt operator+(MinCnt a,MinCnt b){
  MinCnt res(std::min(a.min,b.min),0);
  if(res.min==a.min) res.cnt+=a.cnt;
  if(res.min==b.min) res.cnt+=b.cnt;
  res.cnt%=MOD;
  return res;
}

MinCnt dp1[400005];
MinCnt dp2[400005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&bs[i]);
  }
  std::copy(as,as+N,xs);
  std::copy(bs,bs+N,xs+N);
  std::sort(xs,xs+N*2+1);
  K=std::unique(xs,xs+N*2+1)-xs;
  for(int i=0;i<N;i++){
    int A=std::lower_bound(xs,xs+K,as[i])-xs;
    int B=std::lower_bound(xs,xs+K,bs[i])-xs;
    left[A].push_back(B);
  }
  dp1[0]=MinCnt(0,1);
  MinCnt prefix(dp1[0].shift(-xs[0]));
  int near=-1;
  for(int i=1;i<K;i++){
    for(int j:left[i]){
      dp1[i]=dp1[i]+dp2[j];
      near=std::max(near,j);
    }
    prefix=prefix+dp1[i].shift(-xs[i]);
    dp2[i]=prefix.shift(xs[i]);
  }
  MinCnt ans=std::accumulate(dp1+near+1,dp1+K,MinCnt());
  printf("%d\n",ans.cnt);
}