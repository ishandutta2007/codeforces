#include <iostream>
#include <algorithm>

int as[200];
int bs[200];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=0;i<K;i++){
    std::cin>>bs[i];
  }
  std::sort(bs,bs+N);
  std::reverse(bs,bs+N);
  int j=0;
  for(int i=0;i<N;i++){
    if(as[i]==0){
      as[i]=bs[j++];
    }
  }
  if(std::is_sorted(as,as+N)){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
  }
  return 0;
}