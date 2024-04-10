#include <iostream>
#include <map>

int N;
std::string A,B;

std::map<char,int> moves({{'R',0},{'P',2},{'S',1}});

int win[2]={0,0};
int modwin[2]={0,0};

int main(){
  std::cin>>N>>A>>B;
  for(int i=0;i<A.size()*B.size();i++){
    if(i==N%(A.size()*B.size())){
      modwin[0]=win[0];
      modwin[1]=win[1];
    }
    switch((moves[A[i%A.size()]]+3-moves[B[i%B.size()]])%3){
    case 0:break;
    case 1:win[0]++;break;
    case 2:win[1]++;break;
    }
  }
  int scale=N/(A.size()*B.size());
  std::cout<<(modwin[0]+scale*win[0])<<" "<<(modwin[1]+scale*win[1])<<std::endl;
  return 0;
}