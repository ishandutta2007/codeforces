#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int x,y,xx=0,xn=0,yx=0,yn=0,t=0;
	int a=0,b=0;
	scanf("%d %d",&x,&y);
	for(;;t++){
		switch(t%4){
			case 0:
				if(++xx>=x&&a<=x&&b==y)
				goto end;
				a=xx;
				break;
			case 1:
				if(++yx>=y&&b<=y&&a==x)
				goto end;
				b=yx;
				break;
			case 2:
				if(--xn<=x&&a>=x&&b==y)
				goto end;
				a=xn;
				break;
			case 3:
				if(--yn<=y&&b>=y&&a==x)
				goto end;
				b=yn;
				break;
		}
	}
	end:
	printf("%d",t);
}