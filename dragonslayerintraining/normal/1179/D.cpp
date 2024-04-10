#include <cstdio>
#include <algorithm>
#include <vector>

const int64_t INF=1e18+7;

int64_t sqr(int64_t x){
  return x*x;
}

struct Line{
  int64_t m,b;
  Line(int64_t m,int64_t b):m(m),b(b){
  }
  int64_t eval(int64_t x){
    return m*x+b;
  }
};

struct LCT{
  int left,right;
  struct Line line;
  LCT():left(-1),right(-1),line(0,0){
  }
}nodes[500005];
int nodes_cnt=0;

int new_node(struct Line l){
  nodes[nodes_cnt].line=l;
  return nodes_cnt++;
}

//[L,R]
int insert(int w,int64_t L,int64_t R,struct Line l){
  if(w==-1){
    if(L<=R){
      return new_node(l);
    }else{
      return -1;
    }
  }
  int64_t M=(L+R)/2;
  if(l.eval(M)<nodes[w].line.eval(M)){
    std::swap(nodes[w].line,l);
  }
  if(l.eval(L)<nodes[w].line.eval(L)){
    nodes[w].left=insert(nodes[w].left,L,M-1,l);
  }else{
    nodes[w].right=insert(nodes[w].right,M+1,R,l);
  }
  return w;
}

int64_t query(int w,int64_t L,int64_t R,int64_t x){
  if(w==-1) return INF;
  int64_t M=(L+R)/2;
  int64_t res=nodes[w].line.eval(x);
  if(x<M){
    return std::min(res,query(nodes[w].left,L,M-1,x));
  }else if(x>M){
    return std::min(res,query(nodes[w].right,M+1,R,x));
  }else{
    return res;
  }
}

std::vector<int64_t> edges[500005];
int64_t dp[500005];
int64_t size[500005];
int64_t N;

int64_t best=INF;

void dfs(int64_t node,int64_t parent){
  size[node]=1;
  int envelope=-1;
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dfs(child,node);
    size[node]+=size[child];
    best=std::min(best,sqr(N-size[child])+dp[child]);
    best=std::min(best,query(envelope,0,500000,size[child])+sqr(size[child])+dp[child]-2*N*size[child]);
    envelope=insert(envelope,0,500000,Line(2*size[child],sqr(N)+sqr(size[child])+dp[child]-2*N*size[child]));
  }
  dp[node]=size[node]*size[node];
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    dp[node]=std::min(dp[node],sqr(size[node]-size[child])+dp[child]);
  }
}

int main(){
  scanf("%I64d",&N);
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V;
    scanf("%I64d %I64d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  dfs(0,-1);
  printf("%I64d\n",N*(N-1)-(best-N)/2);
  return 0;
}