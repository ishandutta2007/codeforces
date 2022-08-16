#include <stdio.h>
#include <string.h>
int main(){
	int n,a[1000],t,max=0;
	scanf("%d",&n);
	for(int i=0;i<1000;i++) a[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		a[t-1]++;
	}
	for(int i=0;i<1000;i++)
	if(a[i]>max)max=a[i];
	if(max<=((n+1)/2)) printf("YES");
	else printf("NO");
}