#include <stdio.h>
#include <string.h>
int rt(int x[],int y[]){
	for(int i=0;i<3;i++)
		if(x[i]==x[i+1]&&y[i]==y[i+1])
			return 0;
	for(int i=0;i<3;i++){
int t1=(y[i+2]-y[i+1])*(y[i+1]-y[i]),
		t2=(x[i+2]-x[i+1])*(x[i+1]-x[i]);
	if((t1+t2==0))return 1;
	}
	return 0;
}
int main(){
	int x[6],y[6];
	for(int i=0;i<3;i++){
		scanf("%d %d",&x[i],&y[i]);
		x[i+3]=x[i];
		y[i+3]=y[i];
	}
	if(rt(x,y)){
		printf("RIGHT");return 0;
	}
	for(int i=0;i<3;i++){
		x[i]++;x[i+3]++;
		if(rt(x,y))goto abc;
		x[i]-=2;x[i+3]-=2;
		if(rt(x,y))goto abc;
		x[i]++;x[i+3]++;
		y[i]++;y[i+3]++;
		if(rt(x,y))goto abc;
		y[i]-=2;y[i+3]-=2;
		if(rt(x,y))goto abc;
		y[i]++;y[i+3]++;
	}
	printf("NEITHER");
	return 0;
	abc:
	printf("ALMOST");
}