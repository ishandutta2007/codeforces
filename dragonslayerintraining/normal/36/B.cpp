#include <iostream>
#include <fstream>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

std::vector<std::string> image;

int N,K;

char getcell(int x,int y){
  for(int i=0;i<K;i++){
    if(image[x%N][y%N]=='*'){
      return '*';
    }else{
      x/=N,y/=N;
    }
  }
  return '.';
}

int main(){
  fin>>N>>K;
  image.resize(N);
  for(int i=0;i<N;i++){
    fin>>image[i];
  }
  int D=1;
  for(int i=0;i<K;i++){
    D*=N;
  }
  for(int i=0;i<D;i++){
    for(int j=0;j<D;j++){
      fout<<getcell(i,j);
    }
    fout<<std::endl;
  }
  return 0;
}