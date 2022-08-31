#include <stdio.h>
int c[100010];
int main()
{
	int n;scanf("%d",&n);
	int a[n],b[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
		c[a[i]]++;
	}
	for(int i=0;i<n;i++)
		printf("%d %d\n",(n-1)+c[b[i]],n-1-c[b[i]]);
}