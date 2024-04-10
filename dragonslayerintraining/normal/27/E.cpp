#include <iostream>
#include <vector>

std::vector<long long> factors;

long long getprime(long long nth){
  static std::vector<long long> primes;
  static long long primes_max=1;
  while(primes.size()<=nth){
    for(primes_max++;;primes_max++){
      long long i;
      for(i=0;i<primes.size();i++){
	if(primes_max%primes[i]==0){
	  break;
	}
	if(primes[i]*primes[i]>primes_max){
	  i=primes.size();
	  break;
	}
      }
      if(i==primes.size()){
	primes.push_back(primes_max);
	break;
      }
    }
  }
  return primes[nth];
}

long long best=1e18;

void dfs1(long long index,long long N,long long L,long long ac){
  if(N==1){
    best=std::min(best,ac);
    return;
  }
  long long primepow=getprime(index);
  for(long long i=2;i<=L;i++){
    if(ac*primepow>1e18){
      break;
    }
    if(N%i==0){
      factors.push_back(i);
      dfs1(index+1,N/i,std::min(i,N/i),ac*primepow);
      factors.pop_back();
    }
    primepow*=getprime(index);
  }
}

int main(){
  long long N;
  std::cin>>N;
  dfs1(0,N,N,1);
  std::cout<<best<<std::endl;
  return 0;
}