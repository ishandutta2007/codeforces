#include <stdio.h>
int a[100010],b[100010],c[100010];
int main()
{
	int n,t,r=0;scanf("%d %d",&n,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[r]+=a[i];
		while(b[r]>t&&(r<=i)){
			b[r+1]=b[r]-a[r];
			c[r+1]=c[r]-1;r++;
			if(c[r]<0)c[r]=0;
		}
		if((b[r]<=t)&&(r<=i))c[r]++;
	}
	int max=c[0],i;
	for(i=0;i<=r+2;i++)
	if(c[i]>max) max=c[i];
	printf("%d",max);
}