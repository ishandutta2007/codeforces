#include <iostream>

int prefix[101];

int main(){
  int N;
  std::cin>>N;
  prefix[0]=0;
  for(int i=1;i<=N;i++){
    int X;
    std::cin>>X;
    prefix[i]=prefix[i-1]^X;
  }
  int max=0;
  for(int i=0;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      max=std::max(max,prefix[i]^prefix[j]);
    }
  }
  std::cout<<max<<std::endl;
  return 0;
}