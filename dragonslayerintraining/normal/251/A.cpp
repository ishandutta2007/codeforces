#include <iostream>
#include <stdint.h>

int xs[100000];

int main(){
  int N,D;
  std::cin>>N>>D;
  int j=0;
  int64_t cnt=0;
  for(int i=0;i<N;i++){
    std::cin>>xs[i];
    while(xs[i]-xs[j]>D){
      j++;
    }
    int64_t diff=i-j;
    cnt+=diff*(diff-1)/2;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}