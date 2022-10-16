#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N,K;
int total=0;

int main(){
  fin>>N>>K;
  for(int i=0;i<N;i++){
    int A;
    fin>>A;
    for(int k=0;k<3;k++){
      if(A>=K){
	A-=K;
      }
    }
    total+=A;
  }
  fout<<total<<std::endl;
  return 0;
}