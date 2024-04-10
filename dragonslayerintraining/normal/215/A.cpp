#include <iostream>

int as[51];
int bs[51];

int main(){
  int N,M;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::cin>>M;
  for(int i=0;i<M;i++){
    std::cin>>bs[i];
  }
  int best=0;
  int cnt=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(bs[j]%as[i]==0){
	int rat=bs[j]/as[i];
	if(rat>best){
	  best=rat;
	  cnt=1;
	}else if(rat==best){
	  cnt++;
	}
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}