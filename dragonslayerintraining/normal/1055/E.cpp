#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

const int INF=1e9+7;
int as[1505];
int bs[1505];
int prefix[1505];

int ls[1505];
int rs[1505];
int seg_cnt;
int left[1505];
int N,S,M,K;

int mem[2][1505];

bool check(int X){
  for(int i=1;i<=N;i++){
    prefix[i]=(as[i]<=X)+prefix[i-1];
  }
  int *dp=mem[0];
  int *prev=mem[1];
  for(int i=0;i<seg_cnt;i++){
    prev[i]=0;
  }
  for(int m=0;m<M;m++){
    int best=0;
    int li=0;
    for(int ri=0;ri<seg_cnt;ri++){
      while(rs[li]<=ls[ri]){
	best=std::max(best,prev[li++]);
      }
      dp[ri]=std::max(best+prefix[rs[ri]]-prefix[ls[ri]],
		      prev[li]+prefix[rs[ri]]-prefix[rs[li]]);
    }
    std::swap(dp,prev);
  }
  for(int i=0;i<seg_cnt;i++){
    if(prev[i]>=K) return true;
  }
  return false;
}

int main(){
  scanf("%d %d %d %d",&N,&S,&M,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    bs[i-1]=as[i];
  }
  as[0]=INF;
  std::vector<std::pair<int,int> > tmp;
  for(int i=0;i<S;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    tmp.emplace_back(L-1,-R);
  }
  std::sort(tmp.begin(),tmp.end());
  for(auto seg:tmp){
    int L=seg.first,R=-seg.second;
    if(seg_cnt&&ls[seg_cnt-1]<=L&&rs[seg_cnt-1]>=R) continue;
    ls[seg_cnt]=L,rs[seg_cnt]=R;
    seg_cnt++;
  }
  //binary search
  std::sort(bs,bs+N);
  bs[N]=-1;
  int low=-1,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    int X=bs[mid];
    if(check(X)){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%d\n",bs[high]);
  return 0;
}