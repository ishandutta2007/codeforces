#include <stdio.h>
#include <string.h>
int main(){
	int a,b,f=0,d=0,s=0;
	scanf("%d %d",&a,&b);
	for(int i=1;i<=6;i++){
		int d1=a-i,d2=b-i;
		if(d1<0)d1*=-1;if(d2<0)d2*=-1;
		if(d1<d2)f++;
		else if(d1==d2)d++;
		else s++;
	}
	printf("%d %d %d",f,d,s);
}