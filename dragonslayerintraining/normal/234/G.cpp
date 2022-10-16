#include <fstream>
#include <vector>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main(){
  int N;
  fin>>N;
  for(int k=0;;k++){
    if((1<<k)>=N){
      fout<<k<<std::endl;
      break;
    }
  }
  for(int k=0;(1<<k)<N;k++){
    std::vector<int> vals;
    for(int i=0;i<N;i++){
      if(i&(1<<k)){
	vals.push_back(i);
      }
    }
    fout<<vals.size();
    for(int v:vals){
      fout<<" "<<v;
    }
    fout<<std::endl;
  }
  return 0;
}