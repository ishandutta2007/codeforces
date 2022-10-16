#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

int as[200000];

std::map<int,int> longest;

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    longest[as[i]]=std::max(longest[as[i]],longest[as[i]-1]+1);
  }
  std::pair<int,int> best;
  for(auto pair:longest){
    best=std::max(best,std::make_pair(pair.second,pair.first));
  }
  int curr=best.second;
  std::vector<int> vs;
  for(int i=N-1;i>=0;i--){
    if(as[i]==curr){
      vs.push_back(i);
      curr--;
    }
  }
  printf("%d\n",(int)vs.size());
  std::reverse(vs.begin(),vs.end());
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%d",vs[i]+1);
  }
  printf("\n");
  return 0;
}