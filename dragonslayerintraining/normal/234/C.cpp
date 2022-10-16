#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int as[100000];
int low[100000];

int main(){
  int N;
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>as[i];
  }
  int l=0;
  for(int i=N-1;i>=0;i--){
    low[i]=l;
    if(as[i]<=0){
      l++;
    }
  }
  int h=0;
  int best=1e9;
  for(int i=0;i<N-1;i++){
    if(as[i]>=0){
      h++;
    }
    best=std::min(best,low[i]+h);
  }
  fout<<best<<std::endl;
  return 0;
}