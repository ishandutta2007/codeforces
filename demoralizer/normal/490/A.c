#include <stdio.h>
#include <string.h>
int main(){
	int n,p[3][5000],a[3]={0,0,0},t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		p[t-1][a[t-1]]=i+1;
		a[t-1]++;
	}
	t=(a[0]>a[1])?a[1]:a[0];
	if(a[2]<t)t=a[2];
	printf("%d",t);
	for(int i=0;i<t;i++){
		printf("\n%d %d %d",p[0][i],p[1][i],p[2][i]);
	}
}