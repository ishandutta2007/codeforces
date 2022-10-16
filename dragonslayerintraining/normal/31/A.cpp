#include <iostream>

int worm[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>worm[i];
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
	if(worm[i]==worm[j]+worm[k]){
	  std::cout<<i+1<<" "<<j+1<<" "<<k+1<<std::endl;
	  return 0;
	}
      }
    }
  }
  std::cout<<-1<<std::endl;
  return 0;
}