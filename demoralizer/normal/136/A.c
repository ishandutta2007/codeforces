#include <stdio.h>
#include <string.h>
int main(){
	int n,t;scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[t-1]=i+1;
	}
	for(int i=0;i<n;i++)
	printf("%d ",a[i]);
}