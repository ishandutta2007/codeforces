#include <iostream>
#include <algorithm>

int cnt[3];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    cnt[i%3]+=A;
  }
  switch(std::max_element(cnt,cnt+3)-cnt){
  case 0:std::cout<<"chest"<<std::endl;break;
  case 1:std::cout<<"biceps"<<std::endl;break;
  case 2:std::cout<<"back"<<std::endl;break;
  }
  return 0;
}