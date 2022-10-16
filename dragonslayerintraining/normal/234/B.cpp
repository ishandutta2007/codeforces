#include <fstream>
#include <algorithm>

std::pair<int,int> as[1000];

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int main(){
  int N,K;
  fin>>N>>K;
  for(int i=0;i<N;i++){
    fin>>as[i].first;
    as[i].second=i+1;
  }
  std::sort(as,as+N);
  std::reverse(as,as+N);
  int low=1e9;
  for(int i=0;i<K;i++){
    low=std::min(low,as[i].first);
  }
  fout<<low<<std::endl;
  for(int i=0;i<K;i++){
    if(i>0){
      fout<<" ";
    }
    fout<<as[i].second;
  }
  fout<<std::endl;
  return 0;
}