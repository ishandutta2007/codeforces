#include <iostream>

int vs[10];

int main(){
  int N;
  std::string A;
  std::cin>>N>>A;
  for(int i=0;i<N;i++){
    switch(A[i]){
    case '9':vs[2]-=2;vs[3]+=2;
    case '8':vs[2]+=3;
    case '7':vs[7]++;break;
    case '6':vs[3]++;
    case '5':vs[5]++;break;
    case '4':vs[2]+=2;
    case '3':vs[3]++;break;
    case '2':vs[2]++;break;
    case '1':break;
    case '0':break;
    }
  }
  for(int d=9;d>=0;d--){
    for(int k=0;k<vs[d];k++){
      std::cout<<d;
    }
  }
  std::cout<<std::endl;
  return 0;
}