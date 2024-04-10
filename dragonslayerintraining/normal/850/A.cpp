#include <iostream>
#include <stdint.h>

int64_t points[11][5];

bool bad[11];


int main(){
  int N;
  std::cin>>N;
  if(N>11){
    std::cout<<0<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    for(int d=0;d<5;d++){
      std::cin>>points[i][d];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j){
	continue;
      }
      for(int k=0;k<N;k++){
	if((i==k)||(j==k)){
	  continue;
	}
	int64_t dot=0;
	for(int d=0;d<5;d++){
	  dot+=(points[j][d]-points[i][d])*(points[k][d]-points[i][d]);
	}
	if(dot>0){
	  bad[i]=true;
	}
      }
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    if(!bad[i]){
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  for(int i=0;i<N;i++){
    if(!bad[i]){
      std::cout<<i+1<<std::endl;
    }
  }
  return 0;
}