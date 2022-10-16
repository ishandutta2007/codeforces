#include <iostream>

int used[5000];
int main(){
  int N;
  std::cin>>N;
  int reps=0;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    A--;
    if(A>=N){
      reps++;
      continue;
    }
    if(used[A]){
      reps++;
    }else{
      used[A]=1;
    }
  }
  std::cout<<reps<<std::endl;
  return 0;
}