#include <iostream>
#include <map>

std::map<std::string,long long> questions;

int main(){
  questions[">"]=0;
  questions[">="]=1;
  questions["<"]=2;
  questions["<="]=3;
  long long N;
  std::cin>>N;
  long long low=-2e9;
  long long high=2e9;
  for(long long i=0;i<N;i++){
    std::string type;
    long long val;
    std::string res;
    std::cin>>type>>val>>res;
    long long ques=questions[type];
    if(res=="N"){
      ques=3-ques;
    }
    switch(ques){
    case 0:low=std::max(low,val+1);break;
    case 1:low=std::max(low,val);break;
    case 2:high=std::min(high,val-1);break;
    case 3:high=std::min(high,val);break;
    }
  }
  if(low<=high){
    std::cout<<low<<std::endl;
  }else{
    std::cout<<"Impossible"<<std::endl;
  }
  return 0;
}