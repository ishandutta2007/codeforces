#include <stdio.h>
#include <string.h>
int main(){
	char a[4][105];
	int b[4],c[4]={0,1,2,3},t,o;
	scanf("%s\n%s\n%s\n%s",a[0],a[1],a[2],a[3]);
	for(int i=0;i<4;i++)
	b[i]=strlen(a[i])-2;
	for(int i=0;i<4;i++)
		for(int j=0;j<3-i;j++)
			if(b[j]>b[j+1]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
				t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
	t=0;
	if((2*b[0])<=b[1]){t++;o=c[0];}
	if((2*b[2])<=b[3]){t++;o=c[3];}
	if(t==1)printf("%c",a[o][0]);
	else printf("C");
}