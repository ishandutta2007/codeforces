#include <iostream>
#include <vector>
#include <set>

std::vector<int> primes;
std::set<int> sums;

void genprimes(int n){
  for(int i=2;i<=n;i++){
    for(int j=0;;j++){
      if(j==primes.size()){
	primes.push_back(i);
	//std::cerr<<"prime: "<<i<<std::endl;
	break;
      }
      if(i%primes[j]==0){
	break;
      }
    }
  }
}

int main(){
  int N,K;
  std::cin>>N>>K;
  genprimes(N);
  for(int i=1;i<primes.size();i++){
    sums.insert(primes[i]+primes[i-1]+1);
  }
  for(int i=0;i<primes.size();i++){
    if(sums.count(primes[i])){
      K--;
    }
  }
  if(K<=0){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}