#include <cstdio>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <map>
#include <vector>

int cs[100005];
int ls[100005];
int rs[100005];

int uf[100005];

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

struct ST{
  struct Node{
    int active_cnt;
    int merge;
  }st[400005];
  void pull(int w,int L,int R){
    assert(R-L>1);
    st[w].active_cnt=st[w*2+1].active_cnt+st[w*2+2].active_cnt;
    st[w].merge=-1;
  }
  void build(int w,int L,int R){
    if(R-L==1){
      st[w].active_cnt=0;
      st[w].merge=-1;
    }else{
      int M=(L+R)/2;
      build(w*2+1,L,M);
      build(w*2+2,M,R);
      pull(w,L,R);
    }
  }
  int merge(int w,int L,int R){
    if(st[w].active_cnt==0) return -1;
    if(st[w].merge!=-1) return st[w].merge;
    if(R-L==1){
      assert(0);
    }else{
      int M=(L+R)/2;
      int a=merge(w*2+1,L,M);
      int b=merge(w*2+2,M,R);
      if(a==-1) return b;
      if(b==-1) return a;
      //printf("merge %d with %d (same)\n",a,b);
      uf[find(a)]=find(b);
      st[w].merge=find(a);
      return find(a);
    }
  }
  void toggle(int w,int L,int R,int i){
    if(i<L||i>=R) return;
    if(R-L==1){
      if(st[w].active_cnt){
	st[w].active_cnt=0;
	st[w].merge=-1;
      }else{
	st[w].active_cnt=1;
	st[w].merge=L;
      }
    }else{
      int M=(L+R)/2;
      toggle(w*2+1,L,M,i);
      toggle(w*2+2,M,R,i);
      pull(w,L,R);
    }
  }
}sts[2];

void solve(){
  int N;
  scanf("%d",&N);
  std::iota(uf,uf+N,0);
  std::map<int,std::pair<std::vector<int>,std::vector<int> > > evs;
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&cs[i],&ls[i],&rs[i]);
    evs[ls[i]].first.push_back(i);
    evs[rs[i]].second.push_back(i);
  }
  sts[0].build(0,0,N);
  sts[1].build(0,0,N);
  for(auto it:evs){
    auto& add=it.second.first;
    auto& rem=it.second.second;
    for(int i:add){
      //printf("merge color %d\n",cs[i]^1);
      int a=sts[cs[i]^1].merge(0,0,N);
      if(a!=-1){
	//printf("merge %d with %d (diff)\n",a,i);
	uf[find(a)]=find(i);
      }
      //printf("add %d (color=%d)\n",i,cs[i]);
      sts[cs[i]].toggle(0,0,N,i);
    }
    for(int i:rem){
      //printf("rem %d (color=%d)\n",i,cs[i]);
      sts[cs[i]].toggle(0,0,N,i);
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(i==find(i)) cnt++;
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}