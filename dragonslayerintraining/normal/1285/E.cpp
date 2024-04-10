#include <cstdio>
#include <cassert>
#include <map>
#include <vector>

struct Node{
  int min;
  bool join_left,join_right;
  int blocks;
}st[1600005];
int lazy[1600005];

void lift(Node& a){
  a.join_left=true;
  a.join_right=true;
  a.blocks=1;
}

Node combine(Node a,Node b){
  if(a.min>b.min){
    lift(a);
  }
  if(a.min<b.min){
    lift(b);
  }
  auto res=Node{std::min(a.min,b.min),a.join_left,b.join_right,a.blocks+b.blocks-(a.join_right&&b.join_left)};
  return res;
}

void pull(int w,int L,int R){
  assert(R-L>1);
  assert(lazy[w]==0);
  st[w]=combine(st[w*2+1],st[w*2+2]);
}

void push(int w,int L,int R){
  if(R-L>1){
    lazy[w*2+1]+=lazy[w];
    lazy[w*2+2]+=lazy[w];
  }
  st[w].min+=lazy[w];
  lazy[w]=0;
}

void build(int w,int L,int R){
  lazy[w]=0;
  if(R-L==1){
    st[w]=Node{0,false,false,0};
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
    pull(w,L,R);
  }
}

void update(int w,int L,int R,int a,int b,int v){
  push(w,L,R);
  if(b<=L||a>=R) return;
  if(a<=L&&b>=R){
    lazy[w]+=v;
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    update(w*2+1,L,M,a,b,v);
    update(w*2+2,M,R,a,b,v);
    pull(w,L,R);
  }
}

Node query(int w,int L,int R){
  assert(w==0);
  push(w,L,R);
  return st[w];
}

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<std::pair<int,int> > segs;
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L=L*2;
    R=R*2+1;
    segs.push_back({L,R});
    cps[L],cps[R];
  }
  {
    int last=0;
    for(auto& it:cps){
      it.second=last++;
    }
    assert(last<=N*2);
  }
  for(int i=0;i<N;i++){
    segs[i].first=cps[segs[i].first];
    segs[i].second=cps[segs[i].second];
  }
  build(0,0,N*2);
  for(int i=0;i<N;i++){
    update(0,0,N*2,segs[i].first,segs[i].second,1);
  }
  int best=1;
  for(int i=0;i<N;i++){
    update(0,0,N*2,segs[i].first,segs[i].second,-1);
    Node res=query(0,0,N*2);
    if(res.min==0){
      best=std::max(best,res.blocks);
    }
    update(0,0,N*2,segs[i].first,segs[i].second,1);
  }
  printf("%d\n",best);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}