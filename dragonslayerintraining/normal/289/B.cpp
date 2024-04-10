#include <cstdio>
#include <algorithm>

int N,D;

int as[10000];

int total=0;

int main(){
  int M;
  scanf("%d %d %d",&N,&M,&D);
  N*=M;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int rem=as[0]%D;
  for(int i=0;i<N;i++){
    if(as[i]%D!=rem){
      printf("-1\n");
      return 0;
    }
    as[i]/=D;
  }
  std::sort(as,as+N);
  for(int i=0;i<N;i++){
    total+=std::abs(as[i]-as[N/2]);
  }
  printf("%d\n",total);
  return 0;
}