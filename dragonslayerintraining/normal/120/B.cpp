#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N,K;

int a[1000];

int main(){
  fin>>N>>K;
  for(int i=0;i<N;i++){
    fin>>a[i];
  }
  for(K--;!a[K];K=(K+1)%N);
  fout<<K+1<<std::endl;
  return 0;
}