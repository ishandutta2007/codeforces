#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

std::vector<std::array<int,3> > segs;

std::vector<int> del;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    segs.push_back({L,R,i});
  }
  std::sort(segs.begin(),segs.end());
  std::set<std::pair<int,int> > active;
  for(auto seg:segs){
    active.insert({seg[1],seg[2]});
    while(active.size()&&active.begin()->first<seg[0]){
      active.erase(active.begin());
    }
    while(active.size()>K){
      del.push_back(active.rbegin()->second);
      active.erase(*active.rbegin());
    }
  }
  printf("%d\n",(int)del.size());
  for(int p:del){
    printf("%d ",p+1);
  }
}