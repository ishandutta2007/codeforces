#include <iostream>

int rows[30],cols[30];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int A;
      std::cin>>A;
      rows[i]+=A;
      cols[j]+=A;
    }
  }
  int cnt=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(cols[j]>rows[i]){
	cnt++;
      }
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}