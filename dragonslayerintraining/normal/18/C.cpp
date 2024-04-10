#include <iostream>

int nums[100000];
int sum=0;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>nums[i];
    sum+=nums[i];
  }
  int cnt=0;
  int sum2=0;
  for(int i=0;i<N-1;i++){
    sum2+=nums[i];
    if(sum2*2==sum){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}