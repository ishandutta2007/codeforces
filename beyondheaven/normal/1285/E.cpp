#include<cstdio>
#include<algorithm>
#define MaxN 200123
int T,n,s;
int l[MaxN],r[MaxN];
int b[MaxN<<1];
int d1[MaxN<<2],d2[MaxN<<2];
inline void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d%d",l+i,r+i);
	s=0;
	for(int i=1;i<=n;++i)
	b[++s]=l[i],b[++s]=r[i];
	std::sort(b+1,b+s+1);
	s=std::unique(b+1,b+s+1)-b-1;
	for(int i=1;i<=n;++i)
	{
		l[i]=std::lower_bound(b+1,b+s+1,l[i])-b;
		r[i]=std::lower_bound(b+1,b+s+1,r[i])-b;
		l[i]*=2;r[i]*=2;
		#ifdef Dubug
		printf("l[%d]=%d,r[%d]=%d\n",i,l[i],i,r[i]);
		#endif
	}
	for(int i=1;i<=n;++i)++d1[l[i]],--d1[r[i]+1];
	for(int i=1;i<=2*s+1;++i)d1[i]+=d1[i-1];
	#ifdef Dubug
	for(int i=1;i<=2*s+1;++i)
	printf("%d ",d1[i]);
	puts("");
	#endif
	int ans0=0;
	for(int i=1;i<=2*s+1;++i)
	ans0+=((d1[i]>0&&d1[i+1]==0)?1:0);
	for(int i=1;i<=2*s+1;++i)
	{
		if(d1[i]==1&&d1[i-1]!=1)++d2[i];
		if(d1[i]==1&&d1[i+1]!=1)++d2[i];
	}
	for(int i=1;i<=2*s+1;++i)d2[i]+=d2[i-1];
	int ans1=-0x3f3f3f3f;
	for(int i=1;i<=n;++i)
	{
		int x=(d2[r[i]]-d2[l[i]-1])/2;
		x-=(d1[l[i]]==1?1:0);x-=(d1[r[i]]==1?1:0);
		ans1=std::max(ans1,x);
	}
	printf("%d\n",ans0+ans1);
	for(int i=1;i<=2*s+1;++i)d1[i]=d2[i]=0;
}
int main()
{
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}