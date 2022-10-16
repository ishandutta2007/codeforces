#include <iostream>

int nums[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>nums[i];
  }
  if(nums[0]%2==nums[1]%2){
    for(int i=2;i<N;i++){
      if(nums[i]%2!=nums[0]%2){
	std::cout<<i+1<<std::endl;
	return 0;
      }
    }
  }else if(nums[0]%2==nums[2]%2){
    std::cout<<2<<std::endl;
  }else{
    std::cout<<1<<std::endl;
  }
  return 0;
}