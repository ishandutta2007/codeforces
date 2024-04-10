#include <iostream>

int cover=-1;
int lower=1e9,upper=0;

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<=N;i++){
    int L,R;
    std::cin>>L>>R;
    if((L<=lower)&&(R>=upper)){
      cover=i;
    }else if((L<lower)||(R>upper)){
      cover=-1;
    }
    lower=std::min(lower,L);
    upper=std::max(upper,R);
  }
  std::cout<<cover<<std::endl;
  return 0;
}