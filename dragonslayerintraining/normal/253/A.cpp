#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main(){
  int N,M;
  fin>>N>>M;
  if(N>M){
    while(N+M>0){
      if(N>0){
	fout<<'B';
	N--;
      }
      if(M>0){
	fout<<'G';
	M--;
      }
    }
    fout<<std::endl;
  }else{
    while(N+M>0){
      if(M>0){
	fout<<'G';
	M--;
      }
      if(N>0){
	fout<<'B';
	N--;
      }
    }
    fout<<std::endl;
  }
  return 0;
}