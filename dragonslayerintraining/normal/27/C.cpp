#include <iostream>
#include <vector>

int nums[100000];

int main(){
  int N;
  std::cin>>N;
  
  for(int i=0;i<N;i++){
    std::cin>>nums[i];
  }
  std::vector<int> v;
  int i;
  v.push_back(0);
  for(i=1;i<N;i++){
    if(nums[i]!=nums[0]){
      v.push_back(i);
      break;
    }	
  }
  if(nums[v[0]]<nums[v[1]]){
    for(;i<N;i++){
      if(nums[v[1]]>nums[i]){
	v.push_back(i);
	break;
      }else if(nums[v[1]]<nums[i]){
	v[1]=i;
      }
    }
  }else{
    for(;i<N;i++){
      if(nums[v[1]]<nums[i]){
	v.push_back(i);
	break;
      }else if(nums[v[1]]>nums[i]){
	v[1]=i;
      }
    }
  }
  if(v.size()!=3){
    std::cout<<0<<std::endl;
    return 0;
  }
  std::cout<<3<<std::endl;
  for(int i=0;i<3;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<v[i]+1;
  }
  std::cout<<std::endl;
  return 0;
}