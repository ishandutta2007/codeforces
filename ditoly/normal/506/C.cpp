#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define MM 5000
int h[MN+5],a[MN+5],u[MM+5];
int main()
{
	int n,m,k,p,i;long long l,r,mid,ans,s;
	n=read();m=read();k=read();p=read();
	for(i=1;i<=n;++i)h[i]=read(),a[i]=read();
	for(l=1,r=6e12;l<=r;)
	{
		mid=l+r>>1;
		for(i=1,s=0;i<=n;++i)
		{
			if(h[i]+1LL*a[i]*m<=mid)continue;
			s+=(h[i]+1LL*a[i]*m-mid+p-1)/p;
		}
		if(s>m*k){l=mid+1;continue;}
		memset(u,0,sizeof(u));
		for(i=1;i<=n;++i)
		{
			if(h[i]+1LL*a[i]*m<=mid)continue;
			for(s=h[i]+1LL*a[i]*m-mid;s>0;s-=p)
			{
				if(s<=h[i]){--u[1];continue;}
				if((s-h[i]+a[i]-1)/a[i]+1>m)u[m]-=k+1;
				--u[(s-h[i]+a[i]-1)/a[i]+1];
			}
		}
		for(i=m;i;--i)if((u[i]+=u[i+1]+k)<0)break;
		if(i)l=mid+1;else r=mid-1,ans=mid;
	}
	printf("%I64d",ans);
}