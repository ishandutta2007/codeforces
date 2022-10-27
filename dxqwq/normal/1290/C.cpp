// Problem: C. Prefix Enlightenment
// Contest: Codeforces - Codeforces Round #616 (Div. 1)
// URL: https://codeforces.com/contest/1290/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003][2],fa[1000003];
int col[1000003],flg[1000003];
vector<int> v[1000003];
char s[1000003];
int find(int x)
{
	int tf=fa[x];
	if(x==tf) return x;
	int rt=find(tf);
	if(tf!=rt) col[x]^=col[tf],fa[x]=rt;
	return fa[x];
}
int getv(int x)
{
	if(flg[x]!=-1) return a[x][flg[x]];
	return min(a[x][0],a[x][1]);
}
int c(int x)
{
	if(x==fa[x]) return col[x];
	return col[x]^col[fa[x]];
}
signed main()
{
	int n=read(),m=read();
	scanf("%s",s+1);
	memset(flg,-1,sizeof(flg));
	for(int i=1; i<=m; ++i) fa[i]=i;
	for(int i=1; i<=m; ++i) a[i][0]=1;
	for(int i=1; i<=m; ++i)
		for(int n=read(); n--; v[read()].push_back(i));
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(v[i].empty());
		else if(v[i].size()==1)
		{
			//let a[x]=w
			int x=v[i][0],w=(s[i]=='0');
			int rt=find(x);
			if(flg[rt]==-1)
			{
				ans-=getv(rt);
				if(c(x)!=w)
					swap(a[rt][0],a[rt][1]),
					col[rt]^=1;
				flg[rt]=1;
				ans+=getv(rt);
			}
		} 
		else
		{
			//let a[x]^a[y]=w
			int x=v[i][0],y=v[i][1],w=(s[i]=='0');
			int rx=find(x),ry=find(y);
			// printf("%d %d %d\n",x,y,w);
			if(rx!=ry)
			{
				ans-=getv(rx),ans-=getv(ry);
				if((c(x)^c(y))!=w)
				{
					if(flg[rx]==-1) 
					col[rx]^=1,swap(a[rx][0],a[rx][1]);
					else if(flg[ry]==-1) 
					col[ry]^=1,swap(a[ry][0],a[ry][1]);
					else assert(0);
				}
				col[rx]=col[rx]^col[ry];
				fa[rx]=ry;
				flg[ry]=max(flg[rx],flg[ry]);
				a[ry][0]+=a[rx][0],a[ry][1]+=a[rx][1];
				ans+=getv(ry);
			}
		}
		printf("%d\n",ans);
		// for(int i=1; i<=m; ++i) find(i);
		// for(int i=1; i<=m; ++i) printf("%d ",c(i));
		// puts("");
		// for(int i=1; i<=m; ++i) printf("%d ",fa[i]);
		// puts("");
	}
	return 0;
}