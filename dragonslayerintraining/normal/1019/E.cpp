#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdint.h>
#include <cassert>
#include <map>
#include <limits>

const double INF=std::numeric_limits<double>::infinity();

struct Edge{
  int64_t other;
  int64_t a,b;
  Edge(int64_t other,int64_t a,int64_t b):other(other),a(a),b(b){
  }
};
std::vector<struct Edge> edges[200005];
int64_t head[100005];

void add_edge(int64_t U,int64_t V,int64_t A,int64_t B){
  edges[U].emplace_back(V,A,B);
  edges[V].emplace_back(U,A,B);
}

struct Slope{
  int64_t a,b;
  Slope(int64_t a,int64_t b):a(a),b(b){
  }
  int64_t at(int64_t x){
    return a*x+b;
  }
};
std::map<int64_t,int64_t> slopesmap;
std::vector<struct Slope> slopes;
std::map<int64_t,int64_t> ansmap;
std::vector<struct Slope> ans;

int64_t size[200005];

bool dead[200005];

void crush(const std::map<int64_t,int64_t>& slopesmap,std::vector<struct Slope>& ac){
  assert(ac.empty());
  for(auto pair:slopesmap){
    int64_t a=pair.first,b=pair.second;
    while(ac.size()>=2&&((long double)(a-ac[ac.size()-1].a)*(ac[ac.size()-1].b-ac[ac.size()-2].b)<=
			 (long double)(b-ac[ac.size()-1].b)*(ac[ac.size()-1].a-ac[ac.size()-2].a))){
      ac.pop_back();
    }
    ac.push_back(Slope(a,b));
  }
}

void combine(const std::vector<struct Slope>& l1,const std::vector<struct Slope>& l2){
  assert(l1.size());
  assert(l2.size());
  int64_t i1=0,i2=0;
  while(true){
    int64_t asum=l1[i1].a+l2[i2].a;
    int64_t bsum=l1[i1].b+l2[i2].b;
    ansmap[asum]=std::max(ansmap[asum],bsum);
    long double x1=(i1+1<l1.size())?((long double)(l1[i1].b-l1[i1+1].b))/(l1[i1+1].a-l1[i1].a):INF;
    long double x2=(i2+1<l2.size())?((long double)(l2[i2].b-l2[i2+1].b))/(l2[i2+1].a-l2[i2].a):INF;
    long double xm=std::min(x1,x2);
    if(xm==INF) break;
    if(xm==x1) i1++;
    if(xm==x2) i2++;
  }
}

void dfs_size(int64_t node,int64_t parent){
  size[node]=1;
  for(auto e:edges[node]){
    int64_t child=e.other;
    if(child==parent||dead[child]) continue;
    dfs_size(child,node);
    size[node]+=size[child];
  }
}

int64_t collect_a,collect_b;
void dfs_collect(int64_t node,int64_t parent){
  slopesmap[collect_a]=std::max(slopesmap[collect_a],collect_b);
  for(auto e:edges[node]){
    int64_t child=e.other;
    if(child==parent||dead[child]) continue;
    collect_a+=e.a;
    collect_b+=e.b;
    dfs_collect(child,node);
    collect_a-=e.a;
    collect_b-=e.b;
  }
}

void dfs_solve(int64_t node){
  dfs_size(node,-1);
  int64_t total_size=size[node];
  int64_t parent=-1;
  while(true){
    int64_t heavy=-1;
    for(auto e:edges[node]){
      int64_t child=e.other;
      if(child==parent||dead[child]) continue;
      if(heavy==-1||size[child]>size[heavy]){
	heavy=child;
      }
    }
    if(heavy!=-1&&size[heavy]*2>=total_size){
      parent=node;
      node=heavy;
    }else{
      break;
    }
  }
  std::vector<std::vector<struct Slope> > branches;
  branches.emplace_back(1,Slope(0,0));
  for(auto e:edges[node]){
    if(dead[e.other]) continue;
    assert(slopesmap.empty());
    assert(slopes.empty());
    collect_a=e.a,collect_b=e.b;
    dfs_collect(e.other,node);
    
    crush(slopesmap,slopes);
    slopesmap.clear();
    
    branches.emplace_back();
    branches.back().swap(slopes);
  }
  for(int64_t i=0;i<branches.size();i++){
    for(int64_t j=0;j<i;j++){
      combine(branches[i],branches[j]);
    }
  }
  dead[node]=true;
  for(auto e:edges[node]){
    if(dead[e.other]) continue;
    dfs_solve(e.other);
  }
}

int main(){
  int64_t N,M;
  scanf("%I64d %I64d",&N,&M);
  std::iota(head,head+N,0);
  int64_t add=N;
  ansmap[0]=0;
  for(int64_t i=0;i<N-1;i++){
    int64_t U,V,A,B;
    scanf("%I64d %I64d %I64d %I64d",&U,&V,&A,&B);
    U--,V--;
    if(edges[head[U]].size()==2){
      add_edge(head[U],add,0,0);
      head[U]=add++;
    }
    if(edges[head[V]].size()==2){
      add_edge(head[V],add,0,0);
      head[V]=add++;
    }
    edges[head[U]].emplace_back(head[V],A,B);
    edges[head[V]].emplace_back(head[U],A,B);
  }
  assert(add<=200005);
  dfs_solve(0);
  crush(ansmap,ans);
  int64_t i=0;
  for(int64_t t=0;t<M;t++){
    while(i+1<ans.size()&&ans[i+1].at(t)>=ans[i].at(t)) i++;
    if(t) printf(" ");
    printf("%I64d",ans[i].at(t));
  }
  printf("\n");
  return 0;
}