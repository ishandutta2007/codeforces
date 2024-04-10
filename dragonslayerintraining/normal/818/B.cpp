#include <iostream>
#include <set>

int as[100];
int ls[100];

std::set<int> left;

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    int L;
    std::cin>>L;
    ls[i]=L-1;
  }
  std::fill(as,as+N,-1);
  for(int i=0;i<N;i++){
    left.insert(i);
  }
  for(int i=0;i<M-1;i++){
    int A=(ls[i+1]-ls[i]+N)%N;
    if((as[ls[i]]==-1)&&left.count(A)){
      as[ls[i]]=A;
      left.erase(A);
    }else if(as[ls[i]]==A){
    }else{
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  for(int i=0;i<N;i++){
    if(as[i]==-1){
      as[i]=*left.begin();
      left.erase(left.begin());
    }
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<((as[i]==0)?N:as[i]);
  }
  std::cout<<std::endl;
  return 0;
}