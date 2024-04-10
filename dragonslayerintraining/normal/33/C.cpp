#include <iostream>

int N;
int nums[100000];
int left[100000];
int right[100000];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>nums[i];
  }
  int best=0;
  int prefix=0;
  for(int i=0;i<N;i++){
    prefix+=nums[i];
    if(best<-2*prefix){
      best=-2*prefix;
    }
    left[i]=best;
  }
  best=0;
  prefix=0;
  for(int i=N-1;i>=0;i--){
    prefix+=nums[i];
    if(best<-2*prefix){
      best=-2*prefix;
    }
    right[i]=best;
  }
  int sum=std::max(0,std::max(right[0],left[N-1]));
  for(int i=1;i<N;i++){
    sum=std::max(sum,left[i-1]+right[i]);
  }
  for(int i=0;i<N;i++){
    sum+=nums[i];
  }
  std::cout<<sum<<std::endl;
  return 0;
}