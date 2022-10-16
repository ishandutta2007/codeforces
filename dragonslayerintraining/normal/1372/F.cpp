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
  assert(times[X]<=2);
  if(X==-1) exit(0);
  scanf("%d",&F);
  return {X,F};
}

//Each mode is returned at most twice (discover and locate)
//If the discover query interval contains x's entire interval, locating the left endpoint will also locate the right endpoint
//By making subqueries left to right, we guarantee it to be right-aligned within the subquery interval. Using the frequency from the subquery, this allows us to locate the left endpoint. Using the frequency from the discover query, we also locate the right endpoint.
//The discover query interval cannot contain the right part of the number's interval because everything to the left of the query interval has already been determined and thus discovered.
//If the discover query interval contains the left part of the number's interval, we can avoid using a query to determine the left endpoint by excluding the rightmost f numbers from queries until x is located.
//When we later encounter x again as mode, it must be the right part. We can then locate the right endpoint using the frequency from the locate query.

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
  //This number appeared before and its left endpoint was previously located
  //Now the right endpoint is located as well
  if(l>0&&as[l-1]==x){
    std::fill(as+l,as+l+freq,x);
    return solve(l+freq,r,cap);
  }
  //Query from left to right
  while(r-l>freq){
    //don't include the rightmost freq numbers in queries until x is located
    //this prevents x from appearing as mode again if the original query only had part of it
    //note that no run of consecutive equal numbers can exceed freq
    int m=std::min(r-freq,l+freq);
    solve(l,m,x);
    //left endpoint has been located
    //fill in x
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
  std::fill(as+l,as+r,x);
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