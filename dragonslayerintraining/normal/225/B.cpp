#include <iostream>
#include <vector>

int F[100];

int main(){
  int S,K;
  std::cin>>S>>K;
  F[0]=1;
  F[1]=1;
  int i;
  for(i=2;;i++){
    F[i]=2*F[i-1];
    if(i>=K+1){
      F[i]-=F[i-K-1];
    }
    if(F[i]>S){
      break;
    }
  }
  std::vector<int> nums;
  for(i--;i>=0;i--){
    if(S>=F[i]){
      nums.push_back(F[i]);
      S-=F[i];
    }
  }
  std::cout<<nums.size()+1<<std::endl;
  std::cout<<0;
  for(int num:nums){
    std::cout<<" "<<num;
  }
  std::cout<<std::endl;
  return 0;
}