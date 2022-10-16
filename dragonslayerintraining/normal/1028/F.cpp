#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <stdint.h>

int gcd(int a,int b){
  while(b){
    a=a%b;
    std::swap(a,b);
  }
  return a;
}

std::map<std::pair<int,int>,int> ans;

std::map<int64_t,std::vector<std::pair<int,int> > > points;
int total_cnt=0;

int main(){
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int T,X,Y;
    scanf("%d %d %d",&T,&X,&Y);
    int g=gcd(X,Y);
    switch(T){
    case 1:{
      int64_t R=int64_t(X)*X+int64_t(Y)*Y;
      for(auto p:points[R]){
	int xx=X+p.first,yy=Y+p.second;
	int gg=gcd(xx,yy);
	ans[{xx/gg,yy/gg}]+=2;
      }
      points[R].emplace_back(X,Y);
      ans[{X/g,Y/g}]++;
      total_cnt++;
      break;
    }
    case 2:{
      int64_t R=int64_t(X)*X+int64_t(Y)*Y;
      std::vector<std::pair<int,int> >& ps=points[R];
      ps.erase(std::find(ps.begin(),ps.end(),std::make_pair(X,Y)));
      ans[{X/g,Y/g}]--;
      for(auto p:ps){
	int xx=X+p.first,yy=Y+p.second;
	int gg=gcd(xx,yy);
	ans[{xx/gg,yy/gg}]-=2;
      }
      total_cnt--;
      break;
    }
    case 3:{
      printf("%d\n",total_cnt-ans[std::make_pair(X/g,Y/g)]);
      break;
    }
    }
  }
  return 0;
}