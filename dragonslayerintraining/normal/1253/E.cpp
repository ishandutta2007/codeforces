#include <cstdio>
#include <vector>
#include <algorithm>

void setmin(int& x,int y){
  x=std::min(x,y);
}

const int INF=1e9+7;

std::vector<std::pair<int,int> > antenna;

int best[100001];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int X,S;
    scanf("%d %d",&X,&S);
    antenna.push_back({X,S});
    if(X-S-1<0&&X+S>M){
      printf("0\n");
      return 0;
    }
  }
  std::fill(best+1,best+M+1,INF);
  std::sort(antenna.begin(),antenna.end());
  for(auto a:antenna){
    int x=a.first,s0=a.second;
    for(int s=s0;(x-s-1>=0)||(x+s<=M);s++){
      setmin(best[std::min(x+s,M)],best[std::max(x-s-1,0)]+s-s0);
    }
    for(int x=M;x>0;x--){
      setmin(best[x-1],best[x]);
    }
  }
  printf("%d\n",best[M]);
}