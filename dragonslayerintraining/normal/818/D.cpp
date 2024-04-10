#include <iostream>

int N;
int A;
int color[1000000];
int bad[1000000];

int main(){
  std::cin>>N>>A;
  A--;
  bad[A]=1;
  for(int i=0;i<N;i++){
    int C;
    std::cin>>C;
    C--;
    if(color[C]<color[A]){
      bad[C]=1;
    }
    color[C]++;
  }
  for(int c=0;c<1000000;c++){
    if(color[c]<color[A]){
      bad[c]=1;
    }
    if(!bad[c]){
      std::cout<<c+1<<std::endl;
      return 0;
    }
  }
  std::cout<<-1<<std::endl;
  return 0;
}