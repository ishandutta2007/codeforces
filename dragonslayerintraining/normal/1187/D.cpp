#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

const int INF=1e9+7;

int as[1000005];
int bs[1000005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  std::map<int,std::pair<std::vector<int>,std::vector<int> > > map;
  for(int i=0;i<N;i++){
    map[as[i]].first.push_back(i);
    map[bs[i]].second.push_back(i);
  }
  std::set<std::pair<int,int> > active;
  active.insert({-INF,-INF});
  active.insert({INF,INF});
  for(auto it:map){
    if(it.second.first.size()!=it.second.second.size()){
      printf("NO\n");
      return;
    }
    for(int i=0;i<it.second.first.size();i++){
      int x=it.second.first[i],y=it.second.second[i];
      std::set<std::pair<int,int> >::iterator curr=active.insert({x,y}).first;
      if(std::prev(curr)->second>curr->second){
	printf("NO\n");
	return;
      }else{
	while(std::next(curr)->second<curr->second){
	  active.erase(std::next(curr));
	}
      }
    }
  }
  printf("YES\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
  return 0;
}