#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define MN 500000
char s[MN+5],t[MN+5];
int n,m,k,nx[MN+5],a[MN+5],b[MN+5];
void cal(int*a)
{
	int i,j;
	for(i=2,j=0;i<=m&&i<=k;nx[i++]=j)
	{
		while(j&&t[j+1]!=t[i])j=nx[j];
		if(t[j+1]==t[i])++j;
	}
	for(i=1,j=0;i<=n;++i)
	{
		while(j&&(j==k||t[j+1]!=s[i]))j=nx[j];
		if(t[j+1]==s[i])++j;
		if(j==m)
		{
			if(i<2*k)printf("Yes\n1 %d",k+1);
			else printf("Yes\n%d %d",i-k-k+1,i-k+1);
			exit(0);
		}
		if(i-k+1>0)a[j]=min(a[j],i);
	}
	for(i=m;i;--i)a[nx[i]]=min(a[nx[i]],a[i]);
}
int main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,s+1,t+1);
	memset(a,40,sizeof(a));cal(a);
	for(int i=1;i<n+1-i;++i)swap(s[i],s[n+1-i]);
	for(int i=1;i<m+1-i;++i)swap(t[i],t[m+1-i]);
	memset(b,40,sizeof(b));cal(b);
	for(int i=0;i<=m;++i)if(a[i]<=n&&b[m-i]<=n&&a[i]<n-b[m-i]+1)
		return 0*printf("Yes\n%d %d",a[i]-k+1,n-b[m-i]+1);
	puts("No");
}