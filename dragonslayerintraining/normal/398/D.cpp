#include <cstdio>
#include <set>
#include <vector>
#include <cassert>

const int PERIOD=7000;

bool online[50005];
std::set<std::pair<int,int> > links;
int N;

//SQRT data structure

std::pair<int,int> rank[50005];

std::vector<std::pair<int,int> > right[50005];
int semi[50005];

void rebuild(){
  for(int i=0;i<N;i++){
    rank[i]={0,i};
    right[i].clear();
    semi[i]=0;
  }
  for(auto e:links){
    rank[e.first].first++;
    rank[e.second].first++;
  }
  for(auto e:links){
    int a=e.first,b=e.second;
    if(rank[a]>rank[b]) std::swap(a,b);
    right[a].push_back({b,1});
  }
  for(int a=0;a<N;a++){
    if(online[a]){
      for(auto e:right[a]){
	semi[e.first]+=e.second;
      }
    }
  }
}

void connect(int a,int b){
  int sgn=links.count({a,b})?-1:1;
  if(links.count({a,b})){
    links.erase({a,b});
  }else{
    links.insert({a,b});
  }
  //
  if(rank[a]>rank[b]) std::swap(a,b);
  right[a].push_back({b,sgn});
  if(online[a]){
    semi[b]+=sgn;
  }
}

void toggle(int a){
  int sgn=online[a]?-1:1;
  online[a]^=1;
  //
  for(auto e:right[a]){
    semi[e.first]+=sgn*e.second;
  }
}

int query(int a){
  int ans=semi[a];
  for(auto e:right[a]){
    if(online[e.first]){
      ans+=e.second;
    }
  }
  return ans;
}

int main(){
  int M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  int O;
  scanf("%d",&O);
  while(O--){
    int X;
    scanf("%d",&X);
    X--;
    online[X]=true;
  }
  while(M--){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    if(A>B) std::swap(A,B);
    links.insert({A,B});
  }
  rebuild();
  while(Q--){
    char T;
    scanf(" %c",&T);
    if(T=='O'||T=='F'){
      int U;
      scanf("%d",&U);
      U--;
      toggle(U);
    }else if(T=='A'||T=='D'){
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      if(U>V) std::swap(U,V);
      connect(U,V);
    }else if(T=='C'){
      int U;
      scanf("%d",&U);
      U--;
      printf("%d\n",query(U));
    }else{
      assert(0);
    }
    if(Q%PERIOD==0){
      //printf("REBUILD %d!\n",Q);
      rebuild();
    }
  } 
  return 0;
}