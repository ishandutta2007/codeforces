#include <iostream>
#include <algorithm>

int as[100000];
int bs[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    bs[i]=as[i];
  }
  std::sort(bs,bs+N);
  int error=0;
  for(int i=0;i<N;i++){
    if(as[i]!=bs[i]){
      error++;
    }
  }
  if(error<=2){
    std::cout<<"YES"<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}