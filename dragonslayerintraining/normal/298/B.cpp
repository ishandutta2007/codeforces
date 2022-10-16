#include <cstdio>

int T,SX,SY,EX,EY;
char wind[100005];

int x0,y0,x1,y1;

int main(){
  scanf("%d %d %d %d %d",&T,&SX,&SY,&EX,&EY);
  x0=x1=SX;
  y0=y1=SY;
  scanf("%s",wind);
  if((SX==EX)&&(SY==EY)){
    printf("0\n");
    return 0;
  }
  for(int i=0;wind[i];i++){
    switch(wind[i]){
    case 'E':x1++;break;
    case 'S':y0--;break;
    case 'W':x0--;break;
    case 'N':y1++;break;
    }
    if((EX>=x0)&&(EX<=x1)&&(EY>=y0)&&(EY<=y1)){
      printf("%d\n",i+1);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}