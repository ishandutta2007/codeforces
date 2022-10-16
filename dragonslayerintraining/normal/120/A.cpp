#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main(){
  std::string dir;
  int rail;
  fin>>dir>>rail;
  fout<<(((dir=="front")^(rail==2))?'L':'R')<<std::endl;
  return 0;
}