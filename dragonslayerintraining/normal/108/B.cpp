#include <iostream>
#include <algorithm>

int a[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
  }
  std::sort(a,a+N);
  for(int i=1;i<N;i++){
    if((a[i]!=a[i-1])&&(a[i]<a[i-1]*2)){
      std::cout<<"YES"<<std::endl;
      return 0;
    }
  }
  std::cout<<"NO"<<std::endl;
  return 0;
}