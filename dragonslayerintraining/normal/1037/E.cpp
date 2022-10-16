#include <cstdio>
#include <vector>
#include <set>
#include <queue>

bool going[200005];
std::set<int> edges[200005];
int cnt;
int ans[200005];

std::vector<std::pair<int,int> > elist;
int N,M,K;

void remove(int X){
  //printf("REMOVE %d\n",X+1);
  std::queue<int> qs;
  qs.push(X);
  while(!qs.empty()){
    int X=qs.front();
    qs.pop();
    if(!going[X]) continue;
    going[X]=false;
    //printf("%d is no longer going\n",X+1);
    cnt--;
    for(int adj:edges[X]){
      edges[adj].erase(X);
      if(edges[adj].size()<K){
	qs.push(adj);
      }
    }
    edges[X].clear();
  }
}

int main(){
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    elist.emplace_back(X,Y);
    edges[X].insert(Y);
    edges[Y].insert(X);
  }
  for(int i=0;i<N;i++){
    going[i]=true;
  }
  cnt=N;
  for(int i=0;i<N;i++){
    if(edges[i].size()<K){
      remove(i);
    }
  }
  for(int i=M-1;i>=0;i--){
    int A=elist[i].first;
    int B=elist[i].second;
    //printf("DAY %d: %d\n",i,cnt);
    ans[i]=cnt;
    if(edges[A].count(B)){
      //printf("REMOVING EDGE %d <=> %d\n",A,B);
      
      edges[A].erase(B);
      edges[B].erase(A);
      if(edges[A].size()<K) remove(A);
      if(edges[B].size()<K) remove(B);
    }
  }
  for(int i=0;i<M;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}