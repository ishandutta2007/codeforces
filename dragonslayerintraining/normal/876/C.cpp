#include <cstdio>
#include <vector>

std::vector<int> vs;

int sod(int N){
  int sum=0;
  for(;N>0;N/=10){
    sum+=N%10;
  }
  return sum;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int X=std::max(1,N-81);X<N;X++){
    if(X+sod(X)==N){
      vs.push_back(X);
    }
  }
  printf("%d\n",(int)vs.size());
  for(int v:vs){
    printf("%d\n",v);
  }
  return 0;
}