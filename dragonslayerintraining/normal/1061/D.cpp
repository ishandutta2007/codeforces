#include <cstdio>
#include <map>
#include <vector>
#include <stdint.h>

const int64_t MOD=1e9+7;

std::map<int64_t,std::pair<int64_t,int64_t> > delta;

int main(){
  int64_t N,X,Y;
  scanf("%I64d %I64d %I64d",&N,&X,&Y);
  for(int64_t i=0;i<N;i++){
    int64_t L,R;
    scanf("%I64d %I64d",&L,&R);
    delta[L].first++;
    delta[R].second++;
  }
  std::vector<std::pair<int64_t,std::pair<int64_t,int64_t> > > events(delta.begin(),delta.end());
  std::vector<int64_t> tentative;
  int64_t rented=0;
  int64_t cost=0;
  for(int64_t i=0;i<events.size();i++){
    int64_t time=events[i].first;
    int64_t open=events[i].second.first;
    int64_t close=events[i].second.second;
    while(open--){
      if(tentative.size()&&Y*(time-tentative.back())<X){
	cost=(cost+Y*(time-tentative.back()))%MOD;
	tentative.pop_back();
      }else{
	cost=(cost+X)%MOD;
      }
      rented++;
    }
    while(close--){
      tentative.push_back(time);
      rented--;
    }
    if(i+1==events.size()) break;
    cost=(cost+(events[i+1].first-events[i].first)*rented%MOD*Y)%MOD;
  }
  printf("%I64d\n",cost);
  return 0;
}