#include <iostream>
#include <algorithm>

int xs[100000];

int main(){
  int N,D;
  std::cin>>N>>D;
  for(int i=0;i<N;i++){
    std::cin>>xs[i];
  }
  std::sort(xs,xs+N);
  int best=N;
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      if(xs[j]-xs[i]>D){
	break;
      }
      best=std::min(best,N-j-1+i);
    }
  }
  std::cout<<best<<std::endl;
  return 0;
}