#include <cstdio>
#include <cassert>
#include <set>
#include <queue>
#include <vector>

class HalfEdgeGraph{
  int N;
  //[edge]
  std::vector<int> prev,next,flip;
  std::vector<int> vertex;
  std::vector<int> len;
  //[vertex]
  std::vector<int> deg;
  std::vector<int> some;
  void create_halfedge(int v){
    int id=vertex.size();
    vertex.push_back(v);
    flip.push_back(id^1);
    if(some[v]>=0){
      prev.push_back(prev[some[v]]);
      next.push_back(some[v]);
      prev[next[id]]=id;
      next[prev[id]]=id;
    }else{
      some[v]=id;
      prev.push_back(id);
      next.push_back(id);
    }
    len.push_back(1);
    deg[v]++;
  }
public:
  HalfEdgeGraph(int N):N(N),deg(N),some(N,-1){
  }
  void connect(int a,int b){
    create_halfedge(a);
    create_halfedge(b);
  }
  void compress(int a){
    if(deg[a]==2){
      //printf("COMPRESSING(%d)\n",a);
      assert(some[a]>=0);
      int b=flip[some[a]],c=flip[next[some[a]]];
      flip[b]=c;
      flip[c]=b;
      len[b]=len[c]=len[b]+len[c];
      deg[a]=0;
      some[a]=-1;
    }
  }
  int degree(int v){
    return deg[v];
  }
  int length(int v){
    assert(deg[v]==1);
    return len[some[v]];
  }
  //trim(leaf)
  //return other side
  int trim(int v){
    assert(deg[v]==1);
    int he=flip[some[v]];
    prev[next[he]]=prev[he];
    next[prev[he]]=next[he];
    deg[vertex[he]]--;
    if(some[vertex[he]]==he) some[vertex[he]]=next[he];
    some[v]=-1;
    deg[v]=0;
    return vertex[he];
  }
};

int ans[100001];

int main(){
  int N;
  scanf("%d",&N);
  struct HalfEdgeGraph graph(N);
  for(int i=0;i<N-1;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    graph.connect(U,V);
  }
  for(int i=0;i<N;i++){
    graph.compress(i);
  }
  std::set<std::pair<int,int> > set;
  std::queue<int> path;
  int unans=N;
  for(int i=0;i<N;i++){
    if(graph.degree(i)!=1){
      ans[unans--]=N;
    }else{
      set.insert(std::make_pair(graph.length(i),i));
    }
  }
  for(int taken=N;unans>0;unans--){
    ans[unans]=taken;
    int node=set.begin()->second;
    int len=set.begin()->first;
    set.erase(set.begin());
    if(graph.degree(node)!=1) break;
    if(graph.length(node)!=len){
      set.insert(std::make_pair(graph.length(node),node));
      unans++;
      continue;
    }
    taken-=graph.length(node);
    //printf("TRIMMED %d len=%d\n",node,graph.length(node));
    graph.compress(graph.trim(node));
  }
  for(int i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}