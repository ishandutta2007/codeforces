#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>

int64_t N,K;

std::map<int64_t,int64_t> diff;
int main(){
  std::cin>>N>>K;
  int64_t num=N+K;
  int64_t den=N;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    A--;
    num+=A;
    for(int64_t i=1;i*i<=A;i++){
      diff[i]+=(A/i)-(A/(i+1));
      if(i<A/i){
	diff[A/i]+=1;
      }
    }
  }
  //sentinels
  diff[0];
  diff[1e12];
  std::vector<std::pair<int64_t,int64_t> > delta(diff.begin(),diff.end());
  int64_t best=0;
  for(int64_t i=delta.size()-1;i>0;i--){
    den+=delta[i].second;
    //Interval: (delta[i-1].first,delta[i].first]
    int64_t D=num/den;
    if(D>delta[i-1].first){
      best=std::max(best,std::min(D,delta[i].first));
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}