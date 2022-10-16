#include <iostream>
#include <cstdio>
#include <algorithm>

int mem[100];
  int T,M;
int nextid;

void alloc(int len){
  int run=0;
  for(int i=0;i<M;i++){
    if(mem[i]==0){run++;}else{run=0;}
    if(run==len){
      int id=++nextid;
      for(int j=0;j<len;j++){
	mem[i-j]=id;
      }
      std::cout<<id<<std::endl;
      return;
    }
  }
  std::cout<<"NULL"<<std::endl;
}

void erase(int id){
  bool success=false;
  for(int i=0;i<M;i++){
    if(mem[i]==id){
      mem[i]=0;
      success=true;
    }
  }
  if((id==0)||!success){
    std::cout<<"ILLEGAL_ERASE_ARGUMENT"<<std::endl;
  }
}

void defragment(){
  std::fill(std::remove(mem,mem+M,0),mem+M,0);
}

int main(){
  std::cin>>T>>M;
  std::string skip;
  std::getline(std::cin,skip);
    
  for(int i=0;i<T;i++){
    std::string line;
    std::getline(std::cin,line);
    int arg;
    if(sscanf(line.c_str(),"alloc %d",&arg)>0){
      alloc(arg);
    }else if(sscanf(line.c_str(),"erase %d",&arg)>0){
      erase(arg);
    }else{
      defragment();
    }
  }
  return 0;
}