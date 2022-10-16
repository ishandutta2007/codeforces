#include <iostream>

bool r[5][5];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    r[A][B]=true;
    r[B][A]=true;
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<i;j++){
      for(int k=0;k<j;k++){
	if(r[i][j]&&r[i][k]&&r[j][k]){
	  std::cout<<"WIN"<<std::endl;
	  return 0;
	}
	if(!r[i][j]&&!r[i][k]&&!r[j][k]){
	  std::cout<<"WIN"<<std::endl;
	  return 0;
	}
      }
    }
  }
  std::cout<<"FAIL"<<std::endl;
  return 0;
}