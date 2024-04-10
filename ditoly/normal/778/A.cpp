#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
char a[MN+5],b[MN+5],s[MN+5];
int p[MN+5];
bool check(int x)
{
	int i,j;
	for(i=0;a[i];++i)s[i]=a[i];
	for(i=0;i<x;++i)s[p[i]-1]=' ';
	for(i=j=0;s[i]&&b[j];++i)if(s[i]==b[j])++j;
	return !b[j];
}
int main()
{
	int i,l=0,r,mid,ans;
	scanf("%s%s",a,b);
	for(r=0;a[r];++r)p[r]=read();
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}