#include <iostream>

int seq[1002];
int diff[1001];
int seqlen=0;

bool valid(int& l,int &r){
  int state=0;
  for(int i=0;i<seqlen-1;i++){
    switch(state){
    case 0:if(diff[i]!=1){state=1;l=i;}break;
    case 1:if(diff[i]!=-1){state=2;r=i;}break;
    case 2:if(diff[i]!=1){return false;}
    }
  }
  return state==2;
}

int main(){
  int N;
  std::cin>>N;
  seq[seqlen++]=0;
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    seq[seqlen++]=num;
  }
  seq[seqlen++]=N+1;
  for(int i=1;i<seqlen;i++){
    diff[i-1]=seq[i]-seq[i-1];
  }
  int l,r;
  if(valid(l,r)){
    std::cout<<l+1<<" "<<r<<std::endl;
  }else{
    std::cout<<"0 0"<<std::endl;
  }
  return 0;
}