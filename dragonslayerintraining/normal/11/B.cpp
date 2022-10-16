#include <iostream>
#include <cmath>

int inversetri(int X){
  long long low=-1,high=1e5;
  while(high-low>1){
    long long mid=(low+high)/2;
    long long val=mid*(mid+1)/2;
    if(val<X){
      low=mid;
    }else{
      high=mid;
    }
  }
  return high;
}

int main(){
  int X;
  std::cin>>X;
  X=std::abs(X);
  long long inv=inversetri(X);
  while(((inv*(inv+1))/2)%2!=X%2){
    inv++;
  }
  std::cout<<inv<<std::endl;
  return 0;
}