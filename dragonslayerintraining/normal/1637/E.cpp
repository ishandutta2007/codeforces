#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

void solve(){
  std::map<int,int> freq;
  std::map<int,std::vector<int>> bycnt;
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    freq[A]++;
  }
  for(auto it:freq){
    bycnt[it.second].push_back(it.first);
  }
  for(auto& it:bycnt){
    std::reverse(it.second.begin(),it.second.end());
  }
  std::set<std::pair<int,int> > bad;
  for(int i=0;i<M;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    bad.emplace(X,Y);
    bad.emplace(Y,X);
  }
  long long best=0;
  for(const auto& it1:bycnt){
    for(const auto& it2:bycnt){
      for(int i=0;i<it1.second.size();i++){
	if(it1.second[i]!=it2.second[0]&&!bad.count(std::make_pair(it1.second[i],it2.second[0]))){
	  //fprintf(stderr,"CAND: (%d+%d)*(%d+%d)\n",it1.first,it2.first,it1.second[i],it2.second[0]);
	  best=std::max(best,1LL*(it1.first+it2.first)*(it1.second[i]+it2.second[0]));
	  break;
	}
	for(int j=0;j<it2.second.size();j++){
	  if(it1.second[i]!=it2.second[j]&&!bad.count(std::make_pair(it1.second[i],it2.second[j]))){
	    //fprintf(stderr,"CAND: (%d+%d)*(%d+%d)\n",it1.first,it2.first,it1.second[i],it2.second[j]);
	    best=std::max(best,1LL*(it1.first+it2.first)*(it1.second[i]+it2.second[j]));
	    break;
	  }
	}
      }
    }
  }
  printf("%lld\n",best);
}


int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}