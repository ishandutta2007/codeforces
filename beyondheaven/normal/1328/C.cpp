#include<cstdio>
#define MaxN 200123
int T,n;
int x[MaxN],a[MaxN],b[MaxN];
inline char NextChar()
{
	char ch=getchar();
	while(ch!='0'&&ch!='1'&&ch!='2')ch=getchar();
	return ch;
}
inline void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)x[i]=NextChar()-'0';
	for(int i=1;i<=n;++i)
	{
		if(x[i]==2)a[i]=b[i]=1;
		else if(x[i]==0)a[i]=b[i]=0;
		else
		{
			a[i]=1;b[i]=0;
			for(int j=i+1;j<=n;++j)a[j]=0,b[j]=x[j];
			break;
		}
	}
	for(int i=1;i<=n;++i)
	printf("%d",a[i]);
	puts("");
	for(int i=1;i<=n;++i)
	printf("%d",b[i]);
	puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}