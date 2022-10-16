#include <cstdio>
#include <cmath>
#include <iomanip>

double low=0,high=INFINITY;

void restrict(int init,int dir,int min,int max){
  if(dir>0){
    low=std::max(low,double(min-init)/dir);
    high=std::min(high,double(max-init)/dir);
  }else if(dir<0){
    low=std::max(low,double(max-init)/dir);
    high=std::min(high,double(min-init)/dir);
  }else if((init<=min)||(init>=max)){
    low=INFINITY;
    high=0;
  }
}

int main(){
  int N;
  int X1,Y1,X2,Y2;
  scanf("%d",&N);
  scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
  for(int i=0;i<N;i++){
    int x,y,xdir,ydir;
    scanf("%d %d %d %d",&x,&y,&xdir,&ydir);
    restrict(x,xdir,X1,X2);
    restrict(y,ydir,Y1,Y2);
  }
  if(low<high){
    printf("%.10lf\n",low);
  }else{
    printf("-1\n");
  }
  return 0;
}