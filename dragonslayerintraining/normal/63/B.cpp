#include <iostream>

int a[100];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int ai;
    std::cin>>ai;
    a[ai-1]++;
  }
  int cnt=0;
  while(a[K-1]<N){
    for(int i=K-1;i>0;i--){
      if(a[i-1]){
	a[i]++;
	a[i-1]--;
      }
    }
    cnt++;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}