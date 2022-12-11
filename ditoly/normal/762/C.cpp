#include<cstdio>
#include<cstring>
#define ML 100000
char a[ML+5],b[ML+5];
int fl[ML+5],fr[ML+5];
int main()
{
	int i,j,la,lb,l,r,mid,a1,a2;
	scanf("%s%s",a+1,b+1);la=strlen(a+1);lb=strlen(b+1);
	for(i=1,fl[0]=j=0;b[i];++i)
	{
		for(++j;j<=la&&a[j]!=b[i];++j);
		fl[i]=j;
	}
	for(i=lb,fr[lb+1]=j=la+1;b[i];--i)
	{
		for(--j;j>0&&a[j]!=b[i];--j);
		fr[i]=j;
	}
	for(l=0,r=lb;l<=r;)
	{
		mid=l+r>>1;
		for(i=0;i+mid<=lb;++i)if(fl[i]<fr[i+mid+1])break;
		if(i+mid<=lb)a1=i,a2=i+mid+1,r=mid-1;
		else l=mid+1;
	}
	for(i=1;i<=a1;++i)putchar(b[i]);
	for(i=a2;b[i];++i)putchar(b[i]);
	if(a2-a1>lb)putchar('-');
}