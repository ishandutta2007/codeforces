#include <stdio.h>
#include <string.h>
int main(){
	int n,m,d;
	scanf("%d %d",&n,&m);
	int a[m];
	for(int i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
		for(int j=0;j<m-1-i;j++)
			if(a[j]>a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
	d=a[n-1]-a[0];
	for(int i=0;(n+i-1)<m;i++){
		int t=a[n+i-1]-a[i];
		if(t<d)d=t;
	}
	printf("%d",d);
}