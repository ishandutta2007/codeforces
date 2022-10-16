#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");

int row[55];
int col[55];
int total;

int main(){
  int N,M;
  fin>>N>>M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      int C;
      fin>>C;
      row[i]+=C;
      col[j]+=C;
      total+=C;
    }
  }
  std::vector<int> target;
  {
    for(int i=0;i<3;i++){
      int C;
      fin>>C;
      target.push_back(C);
    }
    std::sort(target.begin(),target.end());
  }
  for(int i=1;i<=N;i++){
    row[i]+=row[i-1];
  }
  for(int j=1;j<=M;j++){
    col[j]+=col[j-1];
  }
  int cnt=0;
  for(int i=1;i<N;i++){
    for(int j=i+1;j<N;j++){
      std::vector<int> v;
      v.push_back(row[i]);
      v.push_back(row[j]-row[i]);
      v.push_back(row[N]-row[j]);
      std::sort(v.begin(),v.end());
      if(v==target){
	cnt++;
      }
    }
  }
  for(int i=1;i<M;i++){
    for(int j=i+1;j<M;j++){
      std::vector<int> v;
      v.push_back(col[i]);
      v.push_back(col[j]-col[i]);
      v.push_back(col[M]-col[j]);
      std::sort(v.begin(),v.end());
      if(v==target){
	cnt++;
      }
    }
  }
  fout<<cnt<<std::endl;
  return 0;
}