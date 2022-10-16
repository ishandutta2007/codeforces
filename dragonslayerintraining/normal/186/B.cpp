#include <iostream>
#include <algorithm>
#include <algorithm>

std::pair<int,int> h[1000];

int main(){
  int N,T1,T2,K;
  std::cin>>N>>T1>>T2>>K;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    h[i].first=-std::max(A*T1*(100-K)+B*T2*100,
			 B*T1*(100-K)+A*T2*100);
    h[i].second=i+1;
  }
  std::sort(h,h+N);
  for(int i=0;i<N;i++){
    int height=-h[i].first;
    std::cout<<h[i].second<<" "<<height/100<<"."<<height/10%10<<height%10<<std::endl;
  }
  return 0;
}