#include <iostream>

bool istri(int N){
  int low=0,high=1000;
  while(high-low>1){
    int mid=(low+high)/2;
    int t=mid*(mid+1)/2;
    if(t<N){
      low=mid;
    }else if(t>N){
      high=mid;
    }else{
      return true;
    }
  }
  return false;
}

int main(){
  int N;
  std::cin>>N;
  std::cout<<(istri(N)?"YES":"NO")<<std::endl;
  return 0;
}