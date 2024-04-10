#include <iostream>

int shifts[100][10000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    int last=-1;
    for(int j=0;j<M;j++){
      if(str[j]=='1'){
	last=j;
      }
    }
    if(last==-1){
      std::cout<<-1<<std::endl;
      return 0;
    }
    for(int j=0;j<M;j++){
      if(str[j]=='1'){
	last=j;
      }
      shifts[i][j]=(j-last+M)%M;
    }
    for(int j=M-1;j>=0;j--){
      if(str[j]=='1'){
	last=j;
      }
    }
    for(int j=M-1;j>=0;j--){
      if(str[j]=='1'){
	last=j;
      }
      shifts[i][j]=std::min(shifts[i][j],(last-j+M)%M);
    }
  }
  int best=1e9;
  for(int i=0;i<M;i++){
    int sum=0;
    for(int j=0;j<N;j++){
      sum+=shifts[j][i];
    }
    best=std::min(best,sum);
  }
  std::cout<<best<<std::endl;
  
  return 0;
}