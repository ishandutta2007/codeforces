#include <iostream>

int ps[100001];

bool subtask1(int N){
  if(N%2==1){
    return false;
  }
  while(N>0){
    int k;
    for(k=1;k<=N;k<<=1);
    for(int i=(k-1)^N;i<=N;i++){
      ps[i]=(k-1)^i;
    }
    N=((k-1)^N)-1;
  }
  return true;
}

bool subtask2(int N){
  if((N<6)||((N&(N-1))==0)){
    return false;
  }
  if(N==6){
    ps[1]=3;
    ps[3]=2;
    ps[2]=6;
    ps[6]=4;
    ps[4]=5;
    ps[5]=1;
    return true;
  }
  while(N>7){
    int k;
    for(k=1;k<=N;k<<=1);
    k>>=1;
    for(int i=k;i<N;i++){
      ps[i]=i+1;
    }
    ps[N]=k;
    N=k-1;
  }
  //N=7
  ps[1]=3;
  ps[3]=2;
  ps[2]=6;
  ps[6]=4;
  ps[4]=5;
  ps[5]=7;
  ps[7]=1;
  return true;
}

int main(){
  int N;
  std::cin>>N;
  if(subtask1(N)){
    std::cout<<"YES"<<std::endl;
    for(int i=1;i<=N;i++){
      if(i>1){
	std::cout<<" ";
      }
      std::cout<<ps[i];
    }
    std::cout<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  if(subtask2(N)){
    std::cout<<"YES"<<std::endl;
    for(int i=1;i<=N;i++){
      if(i>1){
	std::cout<<" ";
      }
      std::cout<<ps[i];
    }
    std::cout<<std::endl;
  }else{
    std::cout<<"NO"<<std::endl;
  }
  return 0;
}