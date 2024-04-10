#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <stdint.h>

int64_t as[150005];

std::map<int64_t,std::set<int64_t> > where;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    where[as[i]].insert(i);
  }
  for(auto& pair:where){
    int64_t val=pair.first;
    std::set<int64_t>& set=pair.second;
    while(set.size()>1){
      int64_t ind1=*set.begin();
      set.erase(set.begin());
      int64_t ind2=*set.begin();
      set.erase(set.begin());
      as[ind1]=-1;
      as[ind2]=val*2;
      where[val*2].insert(ind2);
    }
  }
  std::vector<int64_t> vs;
  for(int64_t i=1;i<=N;i++){
    if(as[i]>=0){
      vs.push_back(as[i]);
    }
  }
  printf("%I64d\n",(int64_t)vs.size());
  for(int64_t i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%I64d",vs[i]);
  }
  printf("\n");
  return 0;
}