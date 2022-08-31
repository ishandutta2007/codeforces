#include <stdio.h>
#include <string.h>
int main(){
	int n,z;
	scanf("%d",&n);
	int a[n],b[n-1];
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	z=a[n-1]-a[0];
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-1;j++)
			b[j]=a[j+(j>=i)];
		int d=b[1]-b[0];
		for(int j=0;j<n-2;j++){
			int k=b[j+1]-b[j];
			if(k>d)d=k;
		}
		if(d<z)z=d;
	}
	printf("%d",z);
}