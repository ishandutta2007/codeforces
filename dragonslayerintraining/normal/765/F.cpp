#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

const bool debug=false;

const int INF=1e9+7;

void setmin(int& x,int y){x=std::min(x,y);}

struct MinSegTree{
  int N;
  int *st;
  MinSegTree(int N):N(N),st(new int[N*2]){
    std::fill(st+1,st+N*2,INF);
  }
  ~MinSegTree(){
    delete st;
  }
  void pull(int i){
    st[i]=std::min(st[i<<1],st[i<<1|1]);
  }
  void update(int i,int v){
    assert(i>=0&&i<N);
    for(setmin(st[i+=N],v);i>1;i>>=1){
      pull(i>>1);
    }
  }
  int query(int a,int b){
    int res=INF;
    for(a+=N,b+=N;a<b;a>>=1,b>>=1){
      if(a&1) setmin(res,st[a++]);
      if(b&1) setmin(res,st[--b]);
    }
    return res;
  }
};

int as[100005];
std::vector<std::pair<int,int> > queries[100005];
int ans[300005];
int N;

void solve(){
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    cps[as[i]];
  }
  int distinct=0;
  for(auto& it:cps){
    it.second=distinct++;
  }
  struct MinSegTree best(N);
  struct MinSegTree recent(distinct);
  for(int i=N-1;i>=0;i--){
    int rank=cps[as[i]];
    //if(debug) fprintf(stderr,"i=%d, a=%d, rank=%d\n",i,as[i],rank);
    {
      //equal values
      int x=recent.query(rank,rank+1);
      if(x!=INF){
	best.update(x,0);
      }
    }
    {
      //smaller values
      int low=0;
      while(true){
	//if(debug) fprintf(stderr,"low=%d\n",low);
	int x=recent.query(low,rank);
	if(x==INF) break;
	//if(debug) fprintf(stderr,"next value %d (at %d)\n",as[x],x);
	best.update(x,as[i]-as[x]);
	//if(debug) fprintf(stderr,"next low must be > %d\n",(as[i]+as[x])/2);
	low=cps.upper_bound((as[i]+as[x])/2)->second;
      }
    }
    recent.update(rank,i);
    if(debug){
      fprintf(stderr,"best:");
      for(int j=0;j<distinct;j++){
	fprintf(stderr," %d",best.query(j,j+1));
      }
      fprintf(stderr,"\n");
    }
    for(auto q:queries[i]){
      setmin(ans[q.second],best.query(i,q.first));
    }
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    queries[L].push_back({R,i});
  }
  std::fill(ans,ans+Q,INF);
  solve();
  for(int i=0;i<N;i++){
    as[i]=1e9-as[i];
  }
  solve();
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}