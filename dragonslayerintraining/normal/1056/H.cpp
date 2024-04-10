#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

const int SQRT=500;

std::vector<int> paths[300005];

std::vector<std::pair<int,int> > where[300005];
struct State{
  int curr,high,from;
}states[300005];
int N,Q;

std::vector<std::pair<int,int> > next[300005];
int last[300005];
int val[300005];

bool update(int i,int j,int from){
  if((j==states[i].curr+1&&from==states[i].from+1)||
     (j<states[i].high)){
    states[i].high=std::min(states[i].high,j);
    states[i].from=from;
    states[i].curr=j;
    return false;
  }
  return true;
}

void clear(){
  for(int i=0;i<Q;i++){
    states[i].curr=states[i].high=paths[i].size();
  }
}

bool solve(){
  scanf("%d %d",&N,&Q);
  for(int i=1;i<=N;i++){
    where[i].clear();
    next[i].clear();
  }
  for(int i=0;i<Q;i++){
    paths[i].clear();
    int K;
    scanf("%d",&K);
    for(int j=0;j<K;j++){
      int C;
      scanf("%d",&C);
      paths[i].push_back(C);
      where[C].push_back({i,j});
    }
  }
  for(int i=0;i<Q;i++){
    if(paths[i].size()>SQRT){
      clear();
      for(int j=0;j<paths[i].size();j++){
	for(std::pair<int,int> p:where[paths[i][j]]){
	  if(update(p.first,p.second,j)) return true;
	}
      }
    }else{
      for(int j=0;j<paths[i].size();j++){
	for(int k=j+1;k<paths[i].size();k++){
	  next[paths[i][j]].push_back({paths[i][k],paths[i][j+1]});
	}
      }
    }
  }
  std::fill(last,last+N+1,-1);
  for(int i=1;i<=N;i++){
    for(std::pair<int,int> p:next[i]){
      if(last[p.first]==i&&val[p.first]!=p.second) return true;
      last[p.first]=i;
      val[p.first]=p.second;
    }
  }
  return false;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    if(solve()){
      printf("Human\n");
    }else{
      printf("Robot\n");
    }
  }
  return 0;
}