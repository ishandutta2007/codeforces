#include <cstdio>
#include <algorithm>

int N,K;

int big=0,small=0;
int share=0;

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<K;i++){
    int A;
    scanf("%d",&A);
    if(A%2==1){
      share++;
    }
    A=A/2;
    big+=A/2;
    small+=A%2;
  }
  if(big>=N){
    int downgrade=big-N;
    if(small+share+downgrade*2<=2*N){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }else if(small>=N*2){
    int promote=small-N*2;
    if(promote<=share){
      big+=promote;
      share-=promote;
      big+=(share+1)/2;
    }else{
      big+=share;
      promote-=share;
      switch(promote%3){
      case 0:big+=promote/3*2;break;
      case 1:big+=promote/3*2+1;break;
      case 2:big+=promote/3*2+2;break;
      }
    }
    if(big<=N){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }else{
    share=std::max(0,share-(N-big)*2);
    if(small+share<=2*N){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}