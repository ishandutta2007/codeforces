#include <cstdio>

struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  Point(int x,int y):x(x),y(y){
  }
}square[2][4];

int ccw(struct Point p1,struct Point p2,struct Point p3){
  p2.x-=p1.x;
  p2.y-=p1.y;
  p3.x-=p1.x;
  p3.y-=p1.y;
  int res=p2.x*p3.y-p2.y*p3.x;
  return (res<0)?-1:((res>0)?1:0);
}

bool intersect(struct Point p1,struct Point p2,struct Point p3,struct Point p4){
  return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0)&&
    (ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}

bool isin(struct Point poly[4],struct Point p){
  int side=ccw(p,poly[3],poly[0]);
  for(int i=0;i<3;i++){
    if(side!=ccw(p,poly[i],poly[i+1])){
      return false;
    }
  }
  return true;
}

int main(){
  for(int s=0;s<2;s++){
    for(int i=0;i<4;i++){
      scanf("%d %d",&square[s][i].x,&square[s][i].y);
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(intersect(square[0][i],square[0][(i+1)%4],
		   square[1][j],square[1][(j+1)%4])){
	printf("Yes\n");
	return 0;
      }
    }
  }
  for(int i=0;i<4;i++){
    if(isin(square[0],square[1][i])){
      printf("Yes\n");
      return 0;
    }
    if(isin(square[1],square[0][i])){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}