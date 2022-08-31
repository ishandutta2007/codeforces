#include <stdio.h>
#include <string.h>
int main(){
	int n,t;
	scanf("%d",&n);
	int a,b[n],c[n],p=0,q=0,r=0,l=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		if((t<0)&&(p==0))
			{a=t;p=1;continue;}
		if(t>0)b[q++]=t;
		if(t<=0)c[r++]=t;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<r-1-i;j++){
			if(c[j]>c[j+1]){
				t=c[j];
				c[j]=c[j+1];
				c[j+1]=t;
			}
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<q-1-i;j++){
			if(b[j]>b[j+1]){
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	}
	if(q==0){
		q=l=2;
		b[0]=c[0];
		b[1]=c[1];
	}
	printf("1 %d",a);
	printf("\n%d",q);
	for(int i=0;i<q;i++)
		printf(" %d",b[i]);
	printf("\n%d",r-l);
	for(int i=l;i<r;i++)
		printf(" %d",c[i]);
}