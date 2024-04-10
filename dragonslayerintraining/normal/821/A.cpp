#include <iostream>

int as[50][50];
int N;

bool isbad(int i,int j){
  for(int k=0;k<N;k++){
    for(int l=0;l<N;l++){
      if(as[i][k]+as[l][j]==as[i][j]){
	return false;
      }
    }
  }
  return true;
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      std::cin>>as[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if((as[i][j]!=1)&&isbad(i,j)){
	std::cout<<"No"<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<"Yes"<<std::endl;
  return 0;
}