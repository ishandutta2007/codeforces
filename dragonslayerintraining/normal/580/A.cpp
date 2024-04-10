#include <iostream>
#include <algorithm>

int a[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
  }
  int best=1;
  int run=1;
  for(int i=1;i<N;i++){
    if(a[i]>=a[i-1]){
      run++;
      best=std::max(best,run);
    }else{
      run=1;
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}