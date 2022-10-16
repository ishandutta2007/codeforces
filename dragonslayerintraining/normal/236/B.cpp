#include <iostream>

int divisors[1000001];

int main(){
  for(int i=1;i<=1000000;i++){
    for(int k=i;k<=1000000;k+=i){
      divisors[k]++;
    }
  }
  int A,B,C;
  std::cin>>A>>B>>C;
  unsigned int sum=0;
  for(int i=1;i<=A;i++){
    for(int j=1;j<=B;j++){
      for(int k=1;k<=C;k++){
	sum+=static_cast<unsigned int>(divisors[i*j*k]);
      }
    }
  }
  std::cout<<(sum%(1<<30))<<std::endl;
  return 0;
}