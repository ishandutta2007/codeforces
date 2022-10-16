#include <iostream>
#include <vector>

int counts[100000];
std::vector<int> nums;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    num--;
    counts[num]++;
    nums.push_back(counts[num]);
  }
  for(int i=1;i<100000;i++){
    if(counts[i-1]<counts[i]){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  std::cout<<counts[0]<<std::endl;
  for(int i=0;i<nums.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<nums[i];
  }
  std::cout<<std::endl;
  return 0;
}