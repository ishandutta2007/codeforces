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
	if(m<=2)
	{
		printf("%d\n",m);
		return 0;
	}
	int ans=2;
	for(int i=3,x=1,y=2; i<=m; i++)
	{
			if(a[x]==a[i])
			{
				x=i;
			}
			else if(a[y]==a[i])
			{
				y=i;
			}
			else if(!nxt[x])
			{++ans;
				x=i;
			}
			else if(!nxt[y])
			{++ans;
				y=i;
			}
			else if(x==y)
			{assert(0);
			}
			else if(nxt[x]>nxt[y])
			{++ans;
				x=i;
			}
			else ++ans,y=i;
	}
	printf("%d\n",ans);
	return 0;
}