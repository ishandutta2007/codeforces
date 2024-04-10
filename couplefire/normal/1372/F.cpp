#include <cstdio>
#include <algorithm>
#include <cassert>
#include <map>
 
const int INF=1e9+7;
 
int as[200005];
 
std::pair<int,int> query(int l,int r){
  printf("? %d %d\n",l+1,r);
  fflush(stdout);
  int X,F;
  scanf("%d",&X);
  static std::map<int,int> times;
  times[X]++;
  assert(times[X]<=3);
  if(X==-1) exit(0);
  scanf("%d",&F);
  return {X,F};
}
 
//each mode is returned at most three times
//1. discover existence
//2. locate left endpoint
//3. locate right endpoint
void solve(int l,int r,int cap){
  if(l==r) return;
  auto p=query(l,r);
  int x=p.first,freq=p.second;
  //all same
  if(freq==r-l){
    std::fill(as+l,as+r,x);
    return;
  }
  //located cap
  if(x==cap){
    std::fill(as+r-freq,as+r,x);
    return solve(l,r-freq,cap);
  }
  //This number appeared before and its left endpoint has been located
  if(l>0&&as[l-1]==x){
    std::fill(as+l,as+l+freq,x);
    return solve(l+freq,r,cap);
  }
  while(true){
    int m=std::min(r,l+freq);
    solve(l,m,x);
    if(m>=r) return;
    if(as[m-1]==x){
      int start=m-1;
      while(start>l&&as[start-1]==x){
	start--;
      }
      std::fill(as+m,as+start+freq,x);
      return solve(start+freq,r,cap);
    }
    l=m;
  }
}
 
int main(){
  int N;
  scanf("%d",&N);
  solve(0,N,INF);
  printf("!");
  for(int i=0;i<N;i++){
    printf(" %d",as[i]);
  }
  printf("\n");
}