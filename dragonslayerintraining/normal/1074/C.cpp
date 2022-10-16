#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int dir[3][3];

int main(){
  int N;
  scanf("%d",&N);
  for(int a=-1;a<=1;a++){
    for(int b=-1;b<=1;b++){
      dir[a+1][b+1]=-INF;
    }
  }
  for(int i=0;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    for(int a=-1;a<=1;a++){
      for(int b=-1;b<=1;b++){
	dir[a+1][b+1]=std::max(dir[a+1][b+1],a*X+b*Y);
      }
    }
  }
  /*
  for(int a=-1;a<=1;a++){
    for(int b=-1;b<=1;b++){
      printf("dir[%d][%d]=%d\n",a,b,dir[a+1][b+1]);
    }
  }
  */
  int f3=-INF;
  for(int a=0;a<=2;a+=2){
    for(int b=0;b<=2;b+=2){
      f3=std::max(f3,dir[a][b]+dir[2-a][1]+dir[1][2-b]);
    }
  }
  printf("%d",2*f3);
  int f4=dir[0][1]+dir[2][1]+dir[1][0]+dir[1][2];
  for(int i=4;i<=N;i++){
    printf(" %d",2*f4);
  }
  printf("\n");
  return 0;
}