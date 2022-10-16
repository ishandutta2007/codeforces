#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

const int INF=1e9+7;

int as[100005];
int bs[100005];
std::vector<int> voters[100005];//indices of voters for candidate i

int cost=0;

std::vector<int> need[100005];

std::set<std::pair<int,int> > low,high;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&as[i],&bs[i]);
    low.insert({bs[i],i});
    cost+=bs[i];
    voters[as[i]].push_back(i);
  }
  for(int i=1;i<=100000;i++){
    std::sort(voters[i].begin(),voters[i].end(),[](int i,int j){return bs[i]>bs[j];});
    for(int j=0;j<voters[i].size();j++){
      //if you win with j+1 votes, you must've bribed voters[i][j]
      need[j+1].push_back(voters[i][j]);
    }
  }
  int best=INF;
  int forced=0;
  for(int votes=N;votes>0;votes--){
    for(int i:need[votes]){
      //must bribe i
      std::pair<int,int> p{bs[i],i};
      if(low.count(p)){
	low.erase(p);
      }else if(high.count(p)){
	high.erase(p);
	cost+=bs[i];
      }
      forced++;
    }
    if(votes<forced) break;
    while(low.size()>votes-forced){
      assert(low.size());
      cost-=low.rbegin()->first;
      high.insert(*low.rbegin());
      low.erase(*low.rbegin());
    }
    assert(low.size()==votes-forced);
    assert(high.empty()||low.begin()->first<=high.begin()->first);
    best=std::min(best,cost);
  }
  printf("%d\n",best);
  return 0;
}