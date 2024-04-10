#include <iostream>
#include <map>

std::map<int,int> primes;

void factor(int num){
  int num2=num;
  for(int i=2;(i*i<=num)&&(num2>1);i++){
    if(num2%i==0){
      primes[i]++;
      while(num2%i==0){
	num2/=i;
      }
    }
  }
  if(num2>1){
    primes[num2]++;
  }
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int S;
    std::cin>>S;
    factor(S);
  }
  int best=1;
  for(std::map<int,int>::iterator it=primes.begin();it!=primes.end();it++){
    best=std::max(best,it->second);
  }
  std::cout<<best<<std::endl;
  return 0;
}