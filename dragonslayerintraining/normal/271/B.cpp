#include <iostream>
#include <algorithm>

int prime[200001];

int rows[500];
int cols[500];

int main(){
  std::fill(prime+2,prime+200001,1);
  for(int i=2;i<=200000;i++){
    if(prime[i]){
      for(int k=i*2;k<=200000;k+=i){
	prime[k]=0;
      }
    }
  }
  int last=200000;
  for(int i=200000;i>=0;i--){
    if(prime[i]){
      last=i;
    }
    prime[i]=last-i;
  }
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int A;
      std::cin>>A;
      int dist=prime[A];
      rows[i]+=dist;
      cols[j]+=dist;
    }
  }
  std::cout<<std::min(*std::min_element(rows,rows+N),
		      *std::min_element(cols,cols+M))<<std::endl;
  return 0;
}