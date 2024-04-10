#include <iostream>

int as[100000];
int inc[100000];
int dec[100000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  {
    int ac=0;
    dec[0]=0;
    for(int i=1;i<N;i++){
      if(as[i]>as[i-1]){
	ac=i;
      }
      dec[i]=ac;
    }
  }
  {
    int ac=N-1;
    inc[N-1]=N-1;
    for(int i=N-2;i>=0;i--){
      if(as[i]>as[i+1]){
	ac=i;
      }
      inc[i]=ac;
    }
  }
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    R--,L--;
    if(inc[L]>=dec[R]){
      std::cout<<"Yes"<<std::endl;
    }else{
      std::cout<<"No"<<std::endl;
    }
  }
  return 0;
}