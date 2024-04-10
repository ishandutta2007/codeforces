#include <iostream>

int square[1000001];

int main(){
  for(int i=0;i<=1000;i++){
    square[i*i]=1;
  }
  int N;
  std::cin>>N;
  int max=-1e9;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if((A<0)||!square[A]){
      max=std::max(max,A);
    }
  }
  std::cout<<max<<std::endl;
  return 0;
}