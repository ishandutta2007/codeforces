#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	int x[n],y[n],p=0,q=0;
	for(int i=0;i<n;i++)
		scanf("%d %d",&x[i],&y[i]);
	for(int i=0;i<=100;i++)
		for(int j=0;j<n;j++)
			if(x[j]==i){p++;break;}
	for(int i=0;i<=100;i++)
		for(int j=0;j<n;j++)
			if(y[j]==i){q++;break;}
	printf("%d",p<q?p:q);
}