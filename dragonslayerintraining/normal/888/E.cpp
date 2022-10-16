#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t as[100];
int64_t N;
int64_t M;

std::vector<int64_t> left,right;

int64_t best=0;

int main(){
  std::cin>>N>>M;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  left.push_back(0);
  for(int64_t i=0;i<N/2;i++){
    for(int64_t j=0;j<(1<<i);j++){
      left.push_back((left[j]+as[i])%M);
    }
  }
  std::sort(right.begin(),right.end());
  right.push_back(0);
  for(int64_t i=N/2;i<N;i++){
    for(int64_t j=0;j<(1<<(i-N/2));j++){
      right.push_back((right[j]+as[i])%M);
    }
  }
  std::sort(right.begin(),right.end());
  for(int64_t i=0;i<left.size();i++){
    std::vector<int64_t>::iterator it=std::lower_bound(right.begin(),right.end(),M-left[i]);
    if(it==right.begin()){
      best=std::max(best,left[i]+right.back());
    }else{
      it--;
      best=std::max(best,left[i]+*it);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}