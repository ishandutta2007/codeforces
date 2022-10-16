#include <iostream>
#include <fstream>

int main(){
  std::ifstream fin("input.txt");
  std::ofstream fout("output.txt");
  int index;
  fin>>index;
  for(int i=0;i<3;i++){
    int A,B;
    fin>>A>>B;
    if(index==A){
      index=B;
    }else if(index==B){
      index=A;
    }
  }
  fout<<index<<std::endl;
  return 0;
}