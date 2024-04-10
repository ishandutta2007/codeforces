#include <cstdio>
#include <vector>
#include <algorithm>

const int INF=1e9+7;

int as[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int ans=INF;
  for(int ones=0;ones<=1;ones++){
    for(int twos=0;twos<=3;twos++){
      std::vector<int> mini;
      mini.push_back(0);
      for(int i=0;i<ones;i++){
	std::vector<int> tmp;
	for(int x:mini){
	  tmp.push_back(x);
	  tmp.push_back(x+1);
	}
	tmp.swap(mini);
      }
      for(int i=0;i<twos;i++){
	std::vector<int> tmp;
	for(int x:mini){
	  tmp.push_back(x);
	  tmp.push_back(x+2);
	}
	tmp.swap(mini);
      }
      int threes=0;
      for(int i=0;i<N;i++){
	int cost=INF;
	for(int x:mini){
	  if(as[i]>=x && (as[i]-x)%3==0){
	    cost=std::min(cost,(as[i]-x)/3);
	  }
	}
	threes=std::max(threes,cost);
      }
      ans=std::min(ans,ones+twos+threes);
    }
  }
  printf("%d\n",ans);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}