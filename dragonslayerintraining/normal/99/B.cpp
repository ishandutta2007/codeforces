#include <iostream>

int N;
int cup[1000];

bool test(){
  int avg=0;
  for(int i=0;i<N;i++){
    std::cin>>cup[i];
    avg+=cup[i];
  }
  if(avg%N!=0){
    return false;
  }
  avg/=N;
  int more=-1,less=-1;
  for(int i=0;i<N;i++){
    if(cup[i]>avg){
      if(more!=-1){
	return false;
      }else{
	more=i;
      }
    }else if(cup[i]<avg){
      if(less!=-1){
	return false;
      }else{
	less=i;
      }
    }
  }
  if(more==less){
    std::cout<<"Exemplary pages."<<std::endl;
  }else{
    std::cout<<(cup[more]-avg)<<" ml. from cup #"<<less+1<<" to cup #"<<more+1<<"."<<std::endl;
  }
  return true;
}

int main(){
  std::cin>>N;
  if(!test()){
    std::cout<<"Unrecoverable configuration."<<std::endl;
  }
  return 0;
}