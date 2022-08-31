#include <stdio.h>
#include <string.h>
int main(){
	int n,k=1,m;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(k){
		k=0;
		m=a[0];
		for(int i=0;i<n;i++)
			if(m>a[i])m=a[i];
		for(int i=0;i<n;i++)
			if(m!=a[i])a[i]-=m;
		for(int i=0;i<n-1;i++)
			if(a[i]!=a[i+1]){k=1;break;}
	}
	printf("%d",m*n);
}