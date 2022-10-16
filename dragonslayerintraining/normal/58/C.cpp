#include <iostream>
#include <map>

std::map<int,int> as;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(i*2>=N){
      as[A-(N-i-1)]++;
    }else{
      as[A-i]++;
    }
  }
  int best=0,besti=0;
  for(std::map<int,int>::iterator
	it=as.begin();it!=as.end();it++){
    if(it->first<=0){
      continue;
    }
    if(best<it->second){
      best=it->second;
      besti=it->first;
    }
  }
  std::cout<<N-best<<std::endl;
  return 0;
}