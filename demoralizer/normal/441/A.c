#include <stdio.h>
#include <string.h>
int main(){
	int n,v,k=0,t,u;
	scanf("%d %d",&n,&v);
	int a[n];
	for(int i=0;i<n;i++)
	a[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		for(int j=0;j<t;j++){
			scanf("%d",&u);
			if(u<v&&a[i]==0){k++;a[i]=1;}
		}
	}
	printf("%d\n",k);
	for(int i=0;i<n;i++)
	if(a[i])printf("%d ",i+1);
}