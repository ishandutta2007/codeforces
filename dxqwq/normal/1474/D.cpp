
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1000003],b[1000003],c[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		bool f=0;
		int n=read();
		for(int i=1; i<=n; i++) c[i]=b[i]=a[i]=read();
		for(int i=2; i<=n; i++) if(b[i-1]>b[i])
			{
				for(int j=i; j<=n; j++) b[j]=-1;
				break;
			}
			else
			{
				b[i]=b[i]-b[i-1];
			}
		for(int i=n-1; i>=1; i--) if(c[i+1]>c[i])
			{
				for(int j=1; j<=i; j++) c[j]=-1;
				break;
			}
			else
			{
				c[i]=c[i]-c[i+1];
			}
		if(b[n]==0&&c[1]==0)
		{
			puts("YES");
			continue;
		}
		for(int i=2; i+2<=n; i++)
		{
			if(b[i-1]!=-1&&c[i+2]!=-1)
			{
				swap(a[i],a[i+1]);
				if(a[i]>=b[i-1]&&a[i+1]>=c[i+2]&&(a[i]-b[i-1])==(a[i+1]-c[i+2]))
				{
					f=1;
					break;
				}
				swap(a[i],a[i+1]);
			}
		}
		if(f)
		{
			puts("YES");
		}
		else
		{
			swap(a[1],a[2]);
			for(int i=1; i<=n; i++) c[i]=b[i]=a[i];
			for(int i=2; i<=n; i++) if(b[i-1]>b[i])
				{
					for(int j=i; j<=n; j++) b[j]=-1;
					break;
				}
				else
				{
					b[i]=b[i]-b[i-1];
				}
			for(int i=n-1; i>=1; i--) if(c[i+1]>c[i])
				{
					for(int j=1; j<=i; j++) c[j]=-1;
					break;
				}
				else
				{
					c[i]=c[i]-c[i+1];
				}
			if(b[n]==0&&c[1]==0)
			{
				puts("YES");
			}
			else
			{
				swap(a[1],a[2]);
				swap(a[n-1],a[n]);
				for(int i=1; i<=n; i++) c[i]=b[i]=a[i];
				for(int i=2; i<=n; i++) if(b[i-1]>b[i])
					{
						for(int j=i; j<=n; j++) b[j]=-1;
						break;
					}
					else
					{
						b[i]=b[i]-b[i-1];
					}
				for(int i=n-1; i>=1; i--) if(c[i+1]>c[i])
					{
						for(int j=1; j<=i; j++) c[j]=-1;
						break;
					}
					else
					{
						c[i]=c[i]-c[i+1];
					}
				if(b[n]==0&&c[1]==0) puts("YES");
				else puts("NO");
			}
 
		}
	}
	return 0;
}