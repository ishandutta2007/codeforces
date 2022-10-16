#include <fstream>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int cs[100000];

int main(){
  int N;
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>cs[i];
  }
  std::sort(cs,cs+N);
  int j=0;
  int best=0;
  for(int i=0;i<N;i++){
    while(cs[j]*2<cs[i]){
      j++;
    }
    best=std::max(best,i-j+1);
  }
  fout<<N-best<<std::endl;
  return 0;
}