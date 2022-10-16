#include <cstdio>
#include <algorithm>
#include <cmath>

int as[100005];

int sign[100005];
int last[100005];
int toggle=1;

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=1;i<=Q;i++){
    char S;
    int X;
    scanf(" %c %d",&S,&X);
    if(S=='<'){toggle*=-1;X=-X;}
    if(X>=0){
      sign[X+1]=-toggle;
      last[X+1]=i;
    }else{
      toggle*=-1;
      sign[-X]=-toggle;
      last[-X]=i;
    }
    if(S=='<'){toggle*=-1;X=-X;}
  }
  for(int i=1;i<=100000;i++){
    if(last[i-1]>last[i]){
      sign[i]=sign[i-1];
      last[i]=last[i-1];
    }
  }
  for(int i=0;i<N;i++){
    int A=std::abs(as[i]);
    if(sign[A]) as[i]=sign[A]*A;
    if(i) printf(" ");
    printf("%d",as[i]*toggle);
  }
  printf("\n");
  return 0;
}