#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

int N,M;


struct Edge{
  int A,B;
  int W;
  Edge(int A,int B,int W):A(A),B(B),W(W){
  }
};

std::vector<struct Edge> edges;

std::map<int,std::vector<int> > byweight;

struct PUF{
  std::vector<int> parent,weight,size;
  PUF(int N):parent(N),weight(N),size(N){
    std::iota(parent.begin(),parent.end(),0);
    std::fill(size.begin(),size.end(),1);
  }
  void merge(int a,int b,int w){
    a=root(a);
    b=root(b);
    if(a==b){
      return;
    }
    if(size[a]<size[b]){
      std::swap(a,b);
    }
    parent[b]=a;
    weight[b]=w;
    size[a]+=size[b];
  }
  int root(int a){
    while(a!=parent[a]){
      a=parent[a];
    }
    return a;
  }
  int find(int a,int lim){
    while((a!=parent[a])&&(weight[a]<lim)){
      a=parent[a];
    }
    return a;
  }
};

struct ZUF{
  int time;
  std::vector<int> parent,recent;
  ZUF(int N):time(1),parent(N),recent(N){
    std::fill(recent.begin(),recent.end(),0);
  }
private:
  void set(int index,int val){
    parent[index]=val;
    recent[index]=time;
  }
  int get(int index){
    if(recent[index]<time){
      set(index,index);
    }
    return parent[index];
  }
public:
  int find(int a){
    if(a==get(a)){
      return a;
    }
    set(a,find(get(a)));
    return get(a);
  }
  void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
      set(a,b);
    }
  }
  void clear(){
    time++;
  }
};

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B,W;
    scanf("%d %d %d",&A,&B,&W);
    A--,B--;
    edges.emplace_back(A,B,W);
    byweight[W].push_back(i);
  }
  struct PUF puf(N);
  for(std::pair<int,std::vector<int>> it:byweight){
    for(int index:it.second){
      /*
      if(puf.root(edges[index].A)!=puf.root(edges[index].B)){
	printf("%d <=> %d\n",edges[index].A+1,edges[index].B+1);
      }
      */
      puf.merge(edges[index].A,edges[index].B,edges[index].W);
    }
  }
  /*
  for(std::pair<int,std::vector<int>> it:byweight){
    for(int i=0;i<N;i++){
      printf("Weight %d: %d => %d\n",it.first,i+1,puf.find(i,it.first)+1);
    }
  }
  */
  struct ZUF zuf(N);
  int Q;
  scanf("%d",&Q);
  for(int q=0;q<Q;q++){
    byweight.clear();
    int K;
    scanf("%d",&K);
    for(int k=0;k<K;k++){
      int E;
      scanf("%d",&E);
      E--;
      byweight[edges[E].W].push_back(E);
    }
    //printf("QUERY %d\n",q+1);
    bool yes=true;
    for(std::pair<int,std::vector<int>> it:byweight){
      zuf.clear();
      int weight=it.first;
      //printf("WEIGHT: %d\n",weight);
      for(int index:it.second){
	//printf("EDGE: %d <=> %d\n",edges[index].A+1,edges[index].B+1);
	int a=puf.find(edges[index].A,weight);
	int b=puf.find(edges[index].B,weight);
	//printf("Weight: %d: %d -> %d\n",weight,edges[index].A+1,a+1);
	//printf("Weight: %d: %d -> %d\n",weight,edges[index].B+1,b+1);
	if(zuf.find(a)==zuf.find(b)){
	  yes=false;
	}else{
	  zuf.merge(a,b);
	}
      }
    }
    if(yes){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}