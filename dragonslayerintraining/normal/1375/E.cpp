#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

int as[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::vector<std::pair<int,int> > swaps;
  for(int i=0;i<N;i++){
    std::vector<std::pair<int,int> > tmp;
    for(int j=i+1;j<N;j++){
      if(as[j]<as[i]){
	tmp.push_back({-as[j],-j});
      }
    }
    std::sort(tmp.begin(),tmp.end());
    for(auto s:tmp){
      swaps.push_back({i,-s.second});
    }
  }
  printf("%d\n",(int)swaps.size());
  for(auto s:swaps){
    printf("%d %d\n",s.first+1,s.second+1);
  }
}