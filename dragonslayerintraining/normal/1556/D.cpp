#include <cstdio>
#include <algorithm>

int ask(int i,int j){
  int O,A;
  printf("or %d %d\n",i+1,j+1);
  fflush(stdout);
  scanf("%d",&O);
  printf("and %d %d\n",i+1,j+1);
  fflush(stdout);
  scanf("%d",&A);
  return O+A;
}

int as[10004];
  
int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  long long S01=ask(0,1);
  long long S02=ask(0,2);
  long long S12=ask(1,2);
  long long S012=(S01+S02+S12)/2;
  as[0]=S012-S12;
  as[1]=S012-S02;
  as[2]=S012-S01;
  for(int i=3;i<N;i++){
    as[i]=ask(0,i)-as[0];
  }
  std::sort(as,as+N);
  printf("finish %d\n",as[K-1]);
}