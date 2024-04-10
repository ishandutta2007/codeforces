#include <iostream>

int as[200001];

int main(){
  int N,K,Q;
  std::cin>>N>>K>>Q;
  for(int i=0;i<N;i++){
    int L,R;
    std::cin>>L>>R;
    as[L]++;
    as[R+1]--;
  }
  for(int i=1;i<=200000;i++){
    as[i]+=as[i-1];
  }
  for(int i=0;i<=200000;i++){
    as[i]=(as[i]>=K);
  }
  for(int i=1;i<=200000;i++){
    as[i]+=as[i-1];
  }
  for(int i=0;i<Q;i++){
    int A,B;
    std::cin>>A>>B;
    std::cout<<as[B]-as[A-1]<<std::endl;
  }
  return 0;
}