#include <iostream>
#include <algorithm>
#include <fstream>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int N,X;

int cost[300];

int main(){
  fin>>N>>X;
  for(int i=0;i<N;i++){
    fin>>cost[i];
    cost[i]*=(N-i);
  }
  std::sort(cost,cost+N);
  int i;
  for(i=0;i<N;i++){
    if(cost[i]<=X){
      X-=cost[i];
    }else{
      break;
    }
  }
  fout<<i<<std::endl;
  return 0;
}