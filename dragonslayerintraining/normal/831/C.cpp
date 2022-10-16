#include <iostream>
#include <algorithm>
#include <set>

int64_t K,N;

int64_t as[2000];
int64_t bs[2000];

int main(){
  std::cin>>K>>N;
  for(int64_t i=0;i<K;i++){
    std::cin>>as[i];
    as[i]+=as[i-1];
  }
  std::sort(as,as+K);
  
  for(int64_t i=0;i<N;i++){
    std::cin>>bs[i];
  }
  std::sort(bs,bs+N);
  
  std::set<int64_t> opt;
  for(int64_t i=0;i<K;i++){
    int64_t init=as[i]-bs[0];
    bool good=true;
    for(int64_t j=0;j<N;j++){
      if(!std::binary_search(as,as+K,init+bs[j])){
	good=false;
	break;
      }
    }
    if(good){
      opt.insert(init);
    }
  }
  std::cout<<opt.size()<<std::endl;
  return 0;
}