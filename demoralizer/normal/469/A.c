#include <stdio.h>
#include <string.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	a[i]=0;
	int p,t;
	scanf("%d",&p);
	for(int i=0;i<p;i++){
		scanf("%d",&t);
		a[t-1]=1;
	}
	scanf("%d",&p);
	for(int i=0;i<p;i++){
		scanf("%d",&t);
		a[t-1]=1;
	}
	for(int i=0;i<n;i++)
	if(a[i]==0){
		printf("Oh, my keyboard!");
		return 0;}
	printf("I become the guy.");
}