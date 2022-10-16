#include <cstdio>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>

struct Point{
  int x,y;
  Point(int x,int y):x(x),y(y){
  }
  Point():Point(0,0){
  }
  void read(){
    scanf("%d %d",&x,&y);
  }
  struct Point operator-(struct Point p)const{
    return Point(x-p.x,y-p.y);
  }
  double arg(){
    return atan2(y,x);
  }
}ps[305];

int64_t dp[305][6];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    ps[i].read();
  }
  std::vector<std::pair<double,std::pair<int,int> > > edges;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j) continue;
      edges.emplace_back((ps[j]-ps[i]).arg(),std::make_pair(i,j));
    }
  }
  std::sort(edges.begin(),edges.end());
  int64_t ans=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<6;k++){
	dp[j][k]=0;
      }
    }
    dp[i][0]=1;
    for(auto e:edges){
      for(int k=0;k<5;k++){
	dp[e.second.second][k+1]+=dp[e.second.first][k];
      }
    }
    ans+=dp[i][5];
  }
  printf("%I64d\n",ans);
  return 0;
}