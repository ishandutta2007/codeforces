#include <stdio.h>
#include <string.h>
int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int n,t,m;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int s=0;
		for(int j=0;j<a[i];j++){
			scanf("%d",&t);
			s+=t;
		}
		if(i)m=min(m,15*a[i]+5*s);
		else m=15*a[i]+5*s;
	}
	printf("%d",m);
}