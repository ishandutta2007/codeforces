#include <iostream>
#include <map>

long long N;
long long as[100000];

int main(){
  std::cin>>N;
  for(long long i=0;i<N;i++){
    std::cin>>as[i];
  }
  long long prop=0;
  std::map<long long ,long long > trans;
  long long best=0;
  for(long long i=0;i<N;i++){
    prop+=as[i];
    trans[prop]++;
    best=std::max(best,trans[prop]);
  }
  std::cout<<N-best<<std::endl;
  return 0;
}