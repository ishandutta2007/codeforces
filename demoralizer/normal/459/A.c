#include <stdio.h>
#include <string.h>
int dist(int x1,int x2,int y1,int y2){
return ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
	int x1,x2,y1,y2,d;
scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
d=dist(x1,x2,y1,y2);
	if(x1==x2){
		for(int x=-1000;x<=1000;x++)
		if((y2-y1)==(x-x1)){
		printf("%d %d %d %d",x,y1,x,y2);
		return 0;}
	}
	if(y1==y2){
		for(int y=-1000;y<=1000;y++)
		if((x2-x1)==(y-y1)){
		printf("%d %d %d %d",x1,y,x2,y);
		return 0;}
	}
	if((x2-x1==y2-y1)||(x2-x1==y1-y2)){
		printf("%d %d %d %d",x1,y2,x2,y1);
		return 0;
	}
	printf("-1");
}