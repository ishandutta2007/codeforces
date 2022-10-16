#include <cstdio>

int as[20000];

int main(){
  int N;
  scanf("%d",&N);
  int sgn=1;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(as[i]&1){
      as[i]+=sgn;
      sgn*=-1;
    }
  }
  for(int i=0;i<N;i++){
    printf("%d\n",as[i]/2);
  }
}