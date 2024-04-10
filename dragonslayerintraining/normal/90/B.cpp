#include <iostream>
#include <set>

int table[100][100];
int cross[100][100];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char c=' ';
      while(!isalpha(c)){
	c=std::cin.get();
      }
      table[i][j]=c;
    }
  }
  for(int i=0;i<N;i++){
    std::multiset<int> set;
    for(int j=0;j<M;j++){
      set.insert(table[i][j]);
    }
    for(int j=0;j<M;j++){
      if(set.count(table[i][j])>1){
	cross[i][j]=1;
      }
    }
  }
  for(int j=0;j<M;j++){
    std::multiset<int> set;
    for(int i=0;i<N;i++){
      set.insert(table[i][j]);
    }
    for(int i=0;i<N;i++){
      if(set.count(table[i][j])>1){
	cross[i][j]=1;
      }
    }
  }
  std::string str;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!cross[i][j]){
	str+=table[i][j];
      }
    }
  }
  std::cout<<str<<std::endl;
  return 0;
}