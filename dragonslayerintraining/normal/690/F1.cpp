#include <iostream>

int degree[10000];

int main(){
  int N;
  std::cin>>N;
  for(int i=1;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    degree[A]++;
    degree[B]++;
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=degree[i]*(degree[i]-1)/2;
  }
  std::cout<<sum<<std::endl;
  return 0;
}