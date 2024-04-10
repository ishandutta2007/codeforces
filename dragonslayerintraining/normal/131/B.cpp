#include <iostream>

long long as[21];

int main(){
  long long N;
  std::cin>>N;
  for(long long i=0;i<N;i++){
    long long A;
    std::cin>>A;
    as[A+10]++;
  }
  long long sum=as[10]*(as[10]-1)/2;
  for(long long i=1;i<=10;i++){
    sum+=as[10+i]*as[10-i];
  }
  std::cout<<sum<<std::endl;
  return 0;
}