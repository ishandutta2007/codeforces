#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

int as[300*300];
int bs[300*300];
int filled[300*300];

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N*M;i++){
    scanf("%d",&as[i]);
  }
  std::copy(as,as+N*M,bs);
  std::sort(bs,bs+N*M);
  std::map<int,std::queue<std::pair<int,int>> > use;
  for(int i=0;i<N;i++){
    for(int j=M-1;j>=0;j--){
      int k=i*M+j;
      use[bs[k]].push({i,j});
    }
  }
  for(int i=0;i<N*M;i++){
    filled[i]=false;
  }
  int cost=0;
  for(int i=0;i<N*M;i++){
    std::pair<int,int> to=use[as[i]].front();
    use[as[i]].pop();
    for(int j=0;j<to.second;j++){
      if(filled[to.first*M+j]){
	cost++;
      }
    }
    filled[to.first*M+to.second]=true;
  }
  printf("%d\n",cost);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}