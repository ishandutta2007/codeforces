#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int fa[1000003];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	int T=read();
	while(T--)
	{
		int ans=0;
		int n=read(),m=read();
		ans=m;
		for(int i=1; i<=n; i++) fa[i]=i;
		for(int i=1,x,y; i<=m; i++) 
		{
			x=read(),y=read();
			if(x==y) 
			{
				--ans;
				continue;
			}
			x=find(x),y=find(y);
			if(x==y) ++ans;
			else fa[x]=y;
		}
		printf("%d\n",ans);
	}
	return 0;
}