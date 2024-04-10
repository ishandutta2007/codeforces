#include <stdio.h>
#include <string.h>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,m,k,t;
	scanf("%d %d %d",&n,&m,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[i]=t-1;
	}
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(a[j]<a[j+1]){
				int t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
	for(int i=0;i<n;i++){
		if(m<=k){printf("%d",i);return 0;}
		k+=a[i];
	}
	if(m<=k)printf("%d",n);else
	printf("-1");
}