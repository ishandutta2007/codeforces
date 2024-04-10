// Problem: CF566E Restoring Map
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF566E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
bitset<1003> a[1003],b[1003],c;
signed main()
{
	int n=read();
	if(n==2) puts("1 2"),exit(0);
	int q=0;
	for(int i=1; i<=n; ++i)
	{
		int T=read();
		if(T==n) ++q;
		for(;T--;) a[i][read()]=1;
	}
	if(q==n)
	{
		for(int i=2; i<=n; ++i)
			printf("%d %d\n",1,i);
		exit(0);
	}
	bitset<1003> t;
	int p1,p2;
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
		{
			t=a[i]&a[j];
			if(t.count()==2)
			{
				int x=t._Find_first();
				int y=t._Find_next(x);
				if(!b[x][y]) printf("%d %d\n",x,y),p1=x,p2=y;
				b[x][y]=b[y][x]=c[x]=c[y]=1;
			}
		}
	int v=c.count();
	for(int i=1; i<=n; ++i) 
		b[i][i]=c[i];
	if(v==2)
	{
		unordered_map<bitset<1003>,int> mp;
		int sjy=p1;
		for(int i=1; i<=n; ++i) if(a[i].count()!=n&&!mp[a[i]]) 
		{
			for(int j=1; j<=n; ++j) if(j!=p1&&j!=p2&&a[i][j])
				printf("%d %d\n",sjy,j);
			mp[a[i]]=1,sjy=p2;
		}
	}
	else
	{
		a[0].set();
		unordered_map<bitset<1003>,int> mp;
		for(int i=1; i<=n; ++i) if(c[i]) assert(!mp[b[i]]),mp[b[i]]=i;
		for(int i=1; i<=n; ++i) if(!c[i])
		{
			int pos=0;
			for(int j=1; j<=n; ++j) 
				if(a[j][i]&&a[j].count()<a[pos].count()) pos=j;
			assert(pos);
			if(mp[a[pos]&c]) printf("%d %d\n",mp[a[pos]&c],i);
		}
	}
	return 0;
}