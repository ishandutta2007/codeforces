#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <stdint.h>

const int64_t INF=2e9+7;

//Let time be -depth
int64_t current_time;

struct End{
  int64_t x,v;
  int64_t a;
  //At position x at time t
  End(int64_t x,int64_t v,int64_t a,int64_t t=0):x(x-v*t),v(v),a(a){
  }
  bool operator<(struct End other)const{
    int64_t xt=x+v*current_time;
    int64_t oxt=other.x+other.v*current_time;
    if(xt!=oxt) return xt<oxt;
    if(v!=other.v) return v<other.v;//make sure leftward is before rightward
    return false;//else equal
  }
  struct End operator-(){
    return End(x+v*current_time,-v,a,current_time);
  }
  void dump(){
    printf("%I64d[%I64d+%I64dt]",a,x+v*current_time,v);
  }
};

struct Collision{
  int64_t time2;
  struct End e1,e2;
  Collision(struct End e1,struct End e2):e1(e1),e2(e2){
    time2=(e1.x-e2.x)*2/(e2.v-e1.v);
  }
  bool operator<(const struct Collision& other)const{
    if(time2!=other.time2) return time2<other.time2;
    //arbitrarily break ties
    if(e1.x!=other.e1.x) return e1.x<other.e1.x;
    if(e1.v!=other.e1.v) return e1.x<other.e1.v;
    if(e1.a!=other.e1.a) return e1.x<other.e1.a;
    if(e2.x!=other.e2.x) return e2.x<other.e2.x;
    if(e2.v!=other.e2.v) return e2.x<other.e2.v;
    if(e2.a!=other.e2.a) return e2.x<other.e2.a;
    return false;
  }
  void dump(){
    e1.dump(),printf(">%I64d/2<",time2),e2.dump();
  }
};

struct DS{
  std::set<struct End> ends;
  std::set<struct Collision> collide;
  void insertc(struct End e1,struct End e2){
    assert(e1<e2);
    if(e1.v>0&&e2.v<0){
      struct Collision c(e1,e2);
      assert(collide.insert(c).second);
    }
  }
  void erasec(struct End e1,struct End e2){
    assert(e1<e2);
    if(e1.v>0&&e2.v<0){
      struct Collision c(e1,e2);
      assert(collide.count(c));
      collide.erase(c);
    }
  }
  struct End cancel(struct End e1,struct End e2){
    if(e1.a>e2.a){
      return End(e1.x,e1.v,e1.a-e2.a);
    }else{
      return End(e2.x,e2.v,e2.a-e1.a);
    }
  }
  void insert(struct End e){
    if(e.a==0) return;
    if(ends.count(e)){
      e.a+=ends.find(e)->a;
      erase(*ends.find(e));
    }
    auto it=ends.insert(e).first;
    
    auto next=std::next(it);
    if(it!=ends.begin()){
      auto prev=std::prev(it);
      if(next!=ends.end()){
	erasec(*prev,*next);
      }
      insertc(*prev,*it);
    }
    if(next!=ends.end()){
      insertc(*it,*next);
    }
  }
  int64_t prep(int64_t T,int64_t A){
    struct End l(T+1,-1,A,current_time);
    struct End r(T-1,1,A,current_time);
    int Al=ends.count(l)?ends.find(l)->a:0;
    int Ar=ends.count(r)?ends.find(r)->a:0;
    return std::max<int64_t>(0,std::min<int64_t>(A-Al,A-Ar));
  }
  void insert_fish(int64_t T,int64_t A){
    struct End l(T,-1,A,current_time);
    struct End r(T,1,A,current_time);
    if(ends.count(l)){
      r.a-=ends.find(l)->a;
      erase(*ends.find(l));
    }
    if(ends.count(r)){
      l.a-=ends.find(r)->a;
      erase(*ends.find(r));
    }
    assert(l.a>0),assert(r.a>0);
    insert(l);
    insert(r);
  }
  void erase(struct End e){
    auto it=ends.find(e);
    assert(it!=ends.end());
    auto next=std::next(it);
    if(next!=ends.end()){
      erasec(*it,*next);
    }
    if(it!=ends.begin()){
      auto prev=std::prev(it);
      erasec(*prev,*it);
      if(next!=ends.end()){
	insertc(*prev,*next);
      }
    }
    ends.erase(e);
  }
  void annihilate(struct Collision c){
    erase(c.e1);
    erase(c.e2);
    insert(cancel(c.e1,c.e2));
  }
  //Fast-forward to time t
  void ffwd(int64_t t){
    while(collide.size()&&collide.begin()->time2<=t*2){
      annihilate(*collide.begin());
    }
  }
  void swap(struct DS& other){
    std::swap(ends,other.ends);
    std::swap(collide,other.collide);
  }
  //other becomes invalidated
  void merge(struct DS& other){
    if(ends.size()<other.ends.size()){
      swap(other);
    }
    for(auto e:other.ends){
      insert(e);
    }
  }
  int64_t query(){
    int64_t ac=0;
    for(auto it:ends){
      if(it.v>0){
	ac+=it.a;
      }
    }
    return ac;
  }
  void dump(){
    printf("T=%I64d\n",current_time);
    for(auto e:ends){
      printf("FISH: "),e.dump(),printf("\n");
    }
    for(auto c:collide){
      printf("COLLISION :"),c.dump(),printf("\n");
    }
  }
};

std::vector<std::pair<int64_t,int64_t> > edges[100005];
std::vector<std::pair<int64_t,int64_t> > fish[100005];

struct DS dss[100005];
int64_t depth[100005];

void dfs_depth(int64_t node,int64_t parent){
  for(auto e:edges[node]){
    int64_t child=e.first;
    if(child==parent) continue;
    depth[child]=depth[node]+e.second;
    dfs_depth(child,node);
  }
}

void dfs_solve(int64_t node,int64_t parent){
  for(auto e:edges[node]){
    int64_t child=e.first;
    if(child==parent) continue;
    dfs_solve(child,node);
    current_time=-depth[child],dss[child].ffwd(-depth[node]-1);
    current_time=-depth[node]-1,dss[node].merge(dss[child]);
  }
  current_time=-depth[node]-1;
  std::vector<int64_t> ls,rs;
  for(auto& f:fish[node]){
    f.second=dss[node].prep(f.first,f.second);
  }
  dss[node].ffwd(-depth[node]);
  current_time=-depth[node];
  for(auto f:fish[node]){
    int D=f.first,F=f.second;
    current_time=-depth[node];
    dss[node].insert(End(D,1,F,current_time));
    dss[node].insert(End(D,-1,F,current_time));
  }
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V,L;
    scanf("%I64d %I64d %I64d",&U,&V,&L);
    U--,V--;
    edges[U].emplace_back(V,L*2);
    edges[V].emplace_back(U,L*2);
  }
  dfs_depth(0,0);
  int64_t K;
  scanf("%I64d",&K);
  for(int64_t i=0;i<K;i++){
    int64_t D,F,P;
    scanf("%I64d %I64d %I64d",&D,&F,&P);
    P--;
    D*=2;
    current_time=-depth[P];
    fish[P].emplace_back(D,F);
  }
  dfs_solve(0,0);
  current_time=-depth[0];
  dss[0].ffwd(INF);
  printf("%I64d\n",dss[0].query());
  return 0;
}