#include<bits/stdc++.h>
#define MaxN 100123

int a[10];
int n;
int b[MaxN];

int c[MaxN][10],d[MaxN][10],e[MaxN*10];

std::vector<int>tag[MaxN*10];

int s[MaxN];

int main()
{
	for(int i=1;i<=6;++i)
	scanf("%d",a+i);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",b+i);
	std::sort(a+1,a+6+1);
	std::sort(b+1,b+n+1);
	
	int cnt=0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=6;++j)
	c[i][j]=e[++cnt]=b[i]-a[j];
	
	std::sort(e+1,e+cnt+1);
	cnt=std::unique(e+1,e+cnt+1)-e-1;
	
	for(int i=1;i<=n;++i)
	for(int j=1;j<=6;++j)
	{
		d[i][j]=std::lower_bound(e+1,e+cnt+1,c[i][j])-e;
		tag[d[i][j]].push_back(i);
	}
	
	int num=0,ans=0x3f3f3f3f;
	
	for(int l=1,r=0;l<=cnt;++l)
	{
		while(r<cnt&&num<n)
		{
			++r;
			for(int x:tag[r])
			num+=(++s[x]==1);
		}
		#ifdef Dubug
		printf("l=%d r=%d\n",e[l],e[r]);
		#endif
		if(num==n)
		ans=std::min(ans,e[r]-e[l]);
		for(int x:tag[l])
		num-=(--s[x]==0);
	}
	
	printf("%d\n",ans);
	return 0;
}