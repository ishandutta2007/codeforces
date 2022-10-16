#include <iostream>
#include <algorithm>

int main(){
  int N;
  std::cin>>N;
  int a[100];
  int sum=0;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
    sum+=a[i];
  }
  std::sort(a,a+N);
  int semi=0;
  for(int i=N-1;i>=0;i--){
    semi+=a[i];
    if(semi*2>sum){
      std::cout<<N-i<<std::endl;
      return 0;
    }
  }
  return 0;
}