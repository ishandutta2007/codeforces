#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>

int64_t num_chains[42];
int64_t must_handle[42];

std::map<int64_t,int64_t> findbit;

int64_t max_chains=0;
int64_t min_chains;
void findcand(){
  for(int64_t i=0;i<42;i++){
    max_chains+=num_chains[i];
  }
  min_chains=max_chains;
  for(int64_t i=0;i<42;i++){
    for(;num_chains[i]>0;num_chains[i]--,min_chains--){ 
      int64_t cap=0;
      int64_t vol=0;
      for(int64_t k=41;k>=0;k--){
	cap+=num_chains[k];
	vol+=must_handle[k];
	if(cap<vol){
	  return;
	}
      }
      for(int64_t j=0;j<=i;j++){
	must_handle[j]++;
      }
    }
  }
}

int main(){
  for(int64_t i=0;i<42;i++){
    findbit[1LL<<i]=i;
  }
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    int64_t A;
    std::cin>>A;
    if(!(A&(A-1))){
      num_chains[findbit[A]]++;
    }else{
      for(int64_t i=40;i>=0;i--){
	if(A&(1LL<<i)){
	  must_handle[i]++;
	  break;
	}
      }
    }
  }
  for(int64_t i=1;i<42;i++){
    if(num_chains[i]>num_chains[i-1]){
      must_handle[i]+=(num_chains[i]-num_chains[i-1]);
      num_chains[i]=num_chains[i-1];
    }
    num_chains[i-1]-=num_chains[i];
  }
  /*
  for(int64_t i=0;i<42;i++){
    std::cerr<<i<<"\t"<<num_chains[i]<<"\t"<<must_handle[i]<<std::endl;
    }*/
  
  findcand();
  if(min_chains+1<=max_chains){
    for(int64_t i=min_chains+1;i<=max_chains;i++){
      std::cout<<i;
      if(i<max_chains){
	std::cout<<" ";
      }
    }
    std::cout<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  
  
  return 0;
}