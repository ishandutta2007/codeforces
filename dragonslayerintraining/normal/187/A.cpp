#include <iostream>

int N;
int as[200000];
int bs[200000];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int i=0;i<N;i++){
    std::cin>>bs[i];
  }
  int curr=0;
  for(int i=0;i<N;i++){
    if(bs[i]==as[curr]){
      curr++;
    }
  }
  std::cout<<N-curr<<std::endl;
  return 0;
}