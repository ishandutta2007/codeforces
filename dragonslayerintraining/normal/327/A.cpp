#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int run=0;
  int best=0;
  int cnt=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    if(A==0){
      run++;
    }else{
      run--;
      cnt++;
    }
    run=std::max(run,0);
    best=std::max(best,run);
  }
  if(cnt<N){
    std::cout<<cnt+best<<std::endl;
  }else{
    std::cout<<N-1<<std::endl;
  }
}