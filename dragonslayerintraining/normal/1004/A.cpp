#include <cstdio>

int xs[100000];

int main(){
  int N,D;
  scanf("%d %d",&N,&D);
  for(int i=0;i<N;i++){
    scanf("%d",&xs[i]);
  }
  int cnt=2;
  for(int i=0;i<N-1;i++){
    if(xs[i+1]-xs[i]==2*D){
      cnt++;
    }else if(xs[i+1]-xs[i]>2*D){
      cnt+=2;
    }
  }
  printf("%d\n",cnt);
  return 0;
}