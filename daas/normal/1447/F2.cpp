#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define lowbit(k) (k&-k)
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,can[200001],maxn,ans,sum[200001],a[200001],minn[400001];
int c1[200001],c2[200001];
void check(int v)
{
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	int L=1;
	c2[0]=n;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==maxn && c1[a[i]]==v)
		{
			while(a[L]!=maxn)
			{
				--c2[c1[a[L]]];
				--c1[a[L]];
				++c2[c1[a[L]]];
				++L;
			}
			++L;
		}
		else
		{
			--c2[c1[a[i]]];
			++c1[a[i]];
			++c2[c1[a[i]]];
		}
		if(c1[maxn]==v && c2[c1[maxn]]>=2)
			ans=max(ans,i-L+1);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		++can[a[i]];
		if(can[a[i]]>can[maxn])
			maxn=a[i];
	}
	for(int i=1;i<=n;++i)
		sum[i]=sum[i-1]+(a[i]==maxn);
	int lim=sqrt(n);
	for(int col=1;col<=n;++col)
	{
		if(col==maxn)
			continue;
		if(can[col]>=lim)
		{
			for(int i=1;i<=2*n;++i)
				minn[i]=n+1;
			minn[n]=0;
			int sumv=0;
			for(int i=1;i<=n;++i)
			{
				sumv+=(a[i]==col);
				int v=sumv-sum[i]+n;
				ans=max(ans,i-minn[v]);
				minn[v]=min(minn[v],i);
			}
		}
	}
	for(int i=1;i<=lim;++i)
		check(i);
	printf("%d\n",ans);
	return 0;
}