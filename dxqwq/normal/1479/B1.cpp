#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int b[1000003];
int nxt[1000003];
int f[1000003];
signed main()
{
	int n=read(),m=0;
	if(n==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1; i<=n; i++) 
	{
		a[++m]=read(),b[m]=1;
		if(a[m]==a[m-1])
		{
			--m,++b[m];
		}
	}
	for(int i=m; i>=1; i--)
	{
		nxt[i]=f[a[i]];
		f[a[i]]=i;
	}
	int ans=0;
	for(int i=1,x=0,y=0; i<=m; i++)
	{
		if(b[i]==1) 
		{
			++ans;
			if(a[x]==a[i])
			{
				y=i;
			}
			else if(a[y]==a[i])
			{
				x=i;
			}
			else if(!nxt[x])
			{
				y=i;
			}
			else if(!nxt[y])
			{
				x=i;
			}
			else if(x==y)
			{
				x=i;
			}
			else if(nxt[x]<nxt[y])
			{
				x=i;
			}
			else y=i;
		}
		else
		{
			if(a[x]!=a[i])
			{
				++ans;
			}
			if(a[y]!=a[i])
			{
				++ans;
			}
			x=i,y=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}