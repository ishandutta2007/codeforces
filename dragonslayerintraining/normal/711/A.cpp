#include <iostream>

std::string row[1000];
int N;

bool solve(){
  for(int i=0;i<N;i++){
    for(int j=0;j<4;j++){
      if(row[i][j]=='O'&&row[i][j+1]=='O'){
	row[i][j]=row[i][j+1]='+';
	return true;
      }
    }
  }
  return false;
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>row[i];
  }
  if(solve()){
    std::cout<<"YES"<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<row[i]<<std::endl;
    }
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}