#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main(){
  int N;
  std::string str;
  fin>>N>>str;
  for(int i=0;i<N/2;i++){
    if((str[i]=='R')&&(str[i+N/2]=='L')){
      fout<<i+N/2+1<<" "<<i+1<<std::endl;
    }else{
      fout<<i+1<<" "<<i+N/2+1<<std::endl;
    }
  }
  return 0;
}