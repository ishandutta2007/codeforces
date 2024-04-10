#include <cstdio>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

const int BLK=6000;

struct Query{
  int l,r,t;
  bool operator<(Query q)const{
    return std::make_tuple(l/BLK,r/BLK,t)<std::make_tuple(q.l/BLK,q.r/BLK,q.t);
  }
};
std::vector<Query> qs;

struct Update{
  int i,from,to;
};
std::vector<Update> upds;

int as[200005];
int occ[200005];
int freq[200005];

int ans[200005];

void add(int x,int times){
  assert(occ[x]>=0);
  freq[occ[x]]--;
  occ[x]+=times;
  freq[occ[x]]++;
}

void modify(int t,int l,int r){
  int i=upds[t].i;
  if(i==-1) return;
  if(l<=i&&i<r) add(as[i],-1);
  assert(as[i]==upds[t].from||as[i]==upds[t].to);
  as[i]^=upds[t].from^upds[t].to;
  if(l<=i&&i<r) add(as[i],1);
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  std::map<int,int> cps;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    cps[as[i]];
  }
  for(int t=0;t<Q;t++){
    int T,A,B;
    scanf("%d %d %d",&T,&A,&B);
    if(T==1){
      qs.push_back({A-1,B,t});
      upds.push_back({-1,-1,-1});
    }else{
      upds.push_back({A-1,-1,B});
      cps[B];
    }
  }
  int last=0;
  for(auto& it:cps){
    it.second=last++;
  }
  for(int i=0;i<N;i++){
    as[i]=cps[as[i]];
  }
  for(auto& upd:upds){
    if(upd.i!=-1){
      upd.to=cps[upd.to];
      upd.from=as[upd.i];
      as[upd.i]=upd.to;
    }
  }
  std::sort(qs.begin(),qs.end());
  int t=Q;
  int l=0,r=0;
  for(Query q:qs){
    while(r<q.r) add(as[r++],1);
    while(l>q.l) add(as[--l],1);
    while(r>q.r) add(as[--r],-1);
    while(l<q.l) add(as[l++],-1);
    while(t<q.t) modify(t++,l,r);
    while(t>q.t) modify(--t,l,r);
    int mex=1;
    while(freq[mex]) mex++;
    ans[q.t]=mex;
  }
  for(int i=0;i<Q;i++){
    if(upds[i].i==-1){
      printf("%d\n",ans[i]);
    }
  }
  return 0;
}