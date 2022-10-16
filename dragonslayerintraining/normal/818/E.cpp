#include <iostream>
#include <vector>
#include <map>

#include <stdint.h>

int64_t as[100000];

int main(){
  int64_t N,K;
  std::cin>>N>>K;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  
  
  std::map<int64_t,int64_t> Kfactorset;
  {
    int64_t rest=K;
    for(int64_t i=2;i*i<=K;i++){
      if(rest%i==0){
	for(;rest%i==0;rest/=i){
	  Kfactorset[i]++;
	}
      }
    }
    if(rest>1){
      Kfactorset[rest]++;
    }
  }
  std::vector<std::pair<int64_t,int64_t> > Kfactors(Kfactorset.begin(),Kfactorset.end());
  
  std::vector<int64_t> factcnt(Kfactors.size(),0);
  int64_t low=0;
  int64_t total=0;
  for(int64_t i=0;i<N;i++){
    bool good=true;
    for(int64_t k=0;k<Kfactors.size();k++){
      int64_t prime=Kfactors[k].first;
      int64_t lowlimit=Kfactors[k].second;
      for(int64_t A=as[i];A%prime==0;A/=prime){
	factcnt[k]++;
      }
      if(factcnt[k]<lowlimit){
	good=false;
      }
    }
    while(good&&(low<=i)){
      for(int64_t k=0;k<Kfactors.size();k++){
	int64_t prime=Kfactors[k].first;
	int64_t lowlimit=Kfactors[k].second;
	for(int64_t A=as[low];A%prime==0;A/=prime){
	  factcnt[k]--;
	}
	if(factcnt[k]<lowlimit){
	  good=false;
	}
      }
      low++;
    }
    total+=low;
  }
  std::cout<<total<<std::endl;
  return 0;
}