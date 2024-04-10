#include <stdio.h>
int main(void){
	int a,x,y,r=-1;
	scanf("%d%d%d",&a,&x,&y);
	if(y<=0||x>=a||x<=-a||y%a==0){
		puts("-1");	return 0;
	}
	y/=a;
	if(!y){
		if(x*2<a&&x*2>-a)r=1;
	}else if(y&1){
		if(x*2<a&&x*2>-a)r=(y+1)/2*3-1;
	}else{
		if(x)
			r=y/2*3+(x>0);
	}
	printf("%d\n",r);
	return 0;
}