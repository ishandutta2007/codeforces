#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using ll = long long;

const ll INF=5e9;

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::vector<ll> points;
  points.push_back(-INF);
  points.push_back(INF);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    points.push_back(A);
  }
  std::vector<std::vector<std::pair<ll,ll> > > segs(N+1);
  std::sort(points.begin(),points.end());
  for(int i=0;i<M;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    auto it=std::lower_bound(points.begin(),points.end(),L);
    if(*it<=R) continue;
    int k=it-points.begin()-1;
    segs[k].push_back({L,R});
  }
  ll dp[2]={0,0};
  ll next[2];
  for(int i=0;i<N+1;i++){
    segs[i].push_back({points[i],points[i]});
    segs[i].push_back({points[i+1],points[i+1]});
    std::sort(segs[i].begin(),segs[i].end(),[](auto s1,auto s2)->bool{
	return std::make_pair(s1.second,-s1.first)<std::make_pair(s2.second,-s2.first);
      });
    std::vector<std::pair<ll,ll> > keep;
    for(auto seg:segs[i]){
      if(keep.empty()||(seg.first>keep.back().first&&seg.second>keep.back().second)){
	keep.push_back(seg);
      }
    }
    ll trans[2][2]={{INF,INF},{INF,INF}};
    for(int j=0;j+1<keep.size();j++){
      ll L=keep[j].first-points[i];
      ll R=points[i+1]-keep[j+1].second;
      for(int s=0;s<2;s++){
	for(int t=0;t<2;t++){
	  trans[s][t]=std::min(trans[s][t],L*(s+1)+R*(t+1));
	}
      }
    }
    next[0]=std::min(dp[0]+trans[0][1],dp[1]+trans[1][1]);
    next[1]=std::min(dp[0]+trans[0][0],dp[1]+trans[1][0]);
    dp[0]=next[0];
    dp[1]=next[1];
  }
  printf("%lld\n",std::min(dp[0],dp[1]));
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}