#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#define LL long long
using namespace std;
LL a[110000],b[110000],c[110000];
int n,m,tot1,tot2,tot3;
LL f[310000];
int t1[310000],t2[310000];
bool cmp(LL x,LL y)
{
	return x>y;
}
int main()
{
	cin>>n>>m;
	tot1=tot2=tot3=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==1)a[++tot1]=y;
		if (x==2)b[++tot2]=y;
		if (x==3)c[++tot3]=y;
	}
	sort(a+1,a+tot1+1,cmp);
	sort(b+1,b+tot2+1,cmp);
	sort(c+1,c+tot3+1,cmp);
	c[0]=0; for(int i=2;i<=tot3;i++)c[i]+=c[i-1];

	f[0]=0; t1[0]=0; t2[0]=0;
	memset(f,0,sizeof(f));
	for(int i=0;i<=m;i++)
	{
		if (t1[i]<tot1&&f[i+1]<f[i]+a[t1[i]+1]){ f[i+1]=f[i]+a[t1[i]+1]; t1[i+1]=t1[i]+1; t2[i+1]=t2[i]; }
		if (t2[i]<tot2&&f[i+2]<f[i]+b[t2[i]+1]){ f[i+2]=f[i]+b[t2[i]+1]; t1[i+2]=t1[i]; t2[i+2]=t2[i]+1; }
	}

	LL ans=0;
	for(int i=0;i<=m;i++)
	{
		int t=min(tot3,(m-i)/3);
		ans=max(ans,f[i]+c[t]);
	}
	cout<<ans<<endl;
}