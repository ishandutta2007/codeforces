#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define MK 320
int a[MN+5],f[MK+5][MN+5],cnt[MK+5],r[MK+5],ans;
int main()
{
	int n=read(),i,j,k;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n&&i<=MK;++i)
	{
		for(ans=j=0;j++<=n;)
			if(j>n||(!f[0][a[j]]++&&++cnt[0]>i))
			{
				for(k=j>n?n:j;cnt[0];--k)if(!--f[0][a[k]])--cnt[0];
				if(j<=n)f[0][a[j]]=cnt[0]=1;++ans;
			}
		printf("%d ",ans);
	}
	if(i<=n)
	{
		for(ans=j=1;j<=n;r[ans]=++j)
			if(!f[ans][a[j]]++&&++cnt[ans]>i)
			{
				--f[ans][a[j]];--cnt[ans];
				++f[++ans][a[j]];++cnt[ans];
			}
		printf("%d ",ans);
	}
	for(++i;i<=n;++i)
	{
		for(j=1;j<=ans;++j)
		{
			for(k=r[j];k<=n;r[j]=++k)
			{
				if(!--f[j+1][a[k]])--cnt[j+1];
				if(!f[j][a[k]]++&&++cnt[j]>i)
				{
					if(!--f[j][a[k]])--cnt[j];
					if(!f[j+1][a[k]]++)++cnt[j+1];
					break;
				}
			}
			if(k>n)ans=j;
		}
		printf("%d ",ans);
	}
}