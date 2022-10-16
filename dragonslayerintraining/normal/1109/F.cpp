#include <cstdio>
#include <cassert>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stdint.h>

const int INF=1e9+7;

int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

int fs[1005][1005];
std::pair<int,int> where[200005];

bool has[1005][1005];
int uf[200005];
int size[200005];
std::vector<std::tuple<int,int,int> > history;
std::vector<std::pair<int,int> > added;
int N,M;

int find(int a){
  while(a!=uf[a]){
    a=uf[a];
  }
  return a;
}

bool merge(int a,int b){
  a=find(a),b=find(b);
  if(a==b) return true;
  if(size[a]>size[b]) std::swap(a,b);
  history.push_back(std::make_tuple(a,b,uf[a]));
  size[b]+=size[a];
  uf[a]=b;
  return false;
}

void revert(int ufi,int hi){
  //printf("revert(%d,%d)\n",ufi,hi);
  while(history.size()>ufi){
    int a=std::get<0>(history.back());
    int b=std::get<1>(history.back());
    int p=std::get<2>(history.back());
    uf[a]=p;
    size[b]-=size[a];
    history.pop_back();
  }
  while(added.size()>hi){
    has[added.back().first][added.back().second]=false;
    added.pop_back();
  }
}

bool add(int r,int c){
  //printf("add(%d,%d)\n",r,c);
  if(false&&has[r][c]){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
	printf("%d",has[i][j]);
      }
    }
  }
  assert(!has[r][c]);
  for(int d=0;d<4;d++){
    int r2=r+dr[d],c2=c+dc[d];
    if(r2>=0&&r2<N&&c2>=0&&c2<M&&has[r2][c2]){
      if(merge(fs[r][c],fs[r2][c2])) return true;
    }
  }
  has[r][c]=true;
  added.push_back({r,c});
  return false;
}

bool add(int x){
  if(x==N*M) return true;
  return add(where[x].first,where[x].second);
}

int cycle[200005];

//Computes answer for [la,ra)
//[ra,lb) already in data structure
void solve(int la,int ra,int lb){
  if(la==ra) return;
  //printf("solve(%d,%d,%d)\n",la,ra,lb);
  int ma=(la+ra)/2;
  int save1=history.size(),save2=added.size();
  for(int i=ma;i<ra;i++){
    add(i);
  }
  solve(la,ma,lb);
  int mb=lb;
  while(!add(mb)){
    mb++;
  }
  revert(save1,save2);
  for(int i=lb;i<mb;i++){
    add(i);
  }
  solve(ma+1,ra,mb);
  revert(save1,save2);
  cycle[ma]=mb;
}

struct Node{
  int min,cnt;
  Node():min(INF),cnt(0){
  }
  Node(int min,int cnt):min(min),cnt(cnt){
  }
}st[1<<20];
int lazy[1<<20];

struct Node combine(struct Node a,struct Node b){
  struct Node res;
  res.min=std::min(a.min,b.min);
  if(res.min==a.min) res.cnt+=a.cnt;
  if(res.min==b.min) res.cnt+=b.cnt;
  return res;
}

void push(int w,int L,int R){
  if(R-L>1){
    lazy[w<<1]+=lazy[w];
    lazy[w<<1|1]+=lazy[w];
  }
  st[w].min+=lazy[w];
  lazy[w]=0;
}

void pull(int w,int L,int R){
  st[w]=combine(st[w<<1],st[w<<1|1]);
}

void update(int w,int L,int R,int a,int b,int x){
  push(w,L,R);
  if(a>=R||b<=L) return;
  if(a<=L&&b>=R){
    lazy[w]+=x;
    push(w,L,R);
    return;
  }
  int M=(L+R)/2;
  update(w<<1,L,M,a,b,x);
  update(w<<1|1,M,R,a,b,x);
  pull(w,L,R);
}
void update(int a,int b,int x){
  update(1,0,N*M,a,b,x);
}

struct Node query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if(a>=R||b<=L) return Node();
  if(a<=L&&b>=R) return st[w];
  int M=(L+R)/2;
  return combine(query(w<<1,L,M,a,b),query(w<<1|1,M,R,a,b));
}
struct Node query(int a,int b){
  return query(1,0,N*M,a,b);
}

std::vector<int> right[200005];

void adjacent(int x,int y){
  if(x>y) std::swap(x,y);
  right[x].push_back(y);
}

int main(){
  scanf("%d %d",&N,&M);
  std::iota(uf,uf+N*M,0);
  std::fill(size,size+N*M,1);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&fs[i][j]);
      fs[i][j]--;
      where[fs[i][j]]=std::make_pair(i,j);
    }
  }
  {
    int left=0;
    int i=0;
    while(i<N*M){
      if(add(i)){
	revert(0,0);
	solve(left,i,i);
	revert(0,0);
	left=i;
      }else{
	i++;
      }
    }
    revert(0,0);
    solve(left,N*M,N*M);
    revert(0,0);
  }
  /*
  for(int i=0;i<N*M;i++){
    printf("cycle: [%d,%d]\n",i+1,cycle[i]+1);
  }
  */
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(i+1<N) adjacent(fs[i][j],fs[i+1][j]);
      if(j+1<M) adjacent(fs[i][j],fs[i][j+1]);
    }
  }
  std::fill(st,st+4*N*M,Node(0,1));
  int64_t total=0;
  for(int i=N*M-1;i>=0;i--){
    //printf("[%d,%d) +=1\n",i,N*M);
    update(i,N*M,1);
    for(int j:right[i]){
      //printf("[%d,%d) -=1\n",j,N*M);
      update(j,N*M,-1);
    }
    struct Node node=query(i,cycle[i]);
    //printf("query[%d,%d) %d x%d\n",i,cycle[i],node.min,node.cnt);
    assert(node.min>=1);
    if(node.min==1){
      //printf("%d: %d\n",i,node.cnt);
      total+=node.cnt;
    }
  }
  printf("%I64d\n",total);
  return 0;
}