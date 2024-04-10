// Problem: CF232E Quick Tortoise
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF232E
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
struct query{int l,r,x,y;}q[1000003];
char s[503][503];
int n=read(),m=read();
bitset<503> f[503][503],g[503][503];
bool ans[1000003];
void solve(int l,int r,vector<int>&v)
{
	vector<int> ls,rs;
	int mid=(l+r)>>1;
	bool flg=0;
	for(int i:v) 
		if(q[i].r<mid) ls.push_back(i);
		else if(q[i].l>mid) rs.push_back(i);
		else flg=1;
	if(flg)
	{
		for(int i=l; i<=r; ++i)	
			for(int j=1; j<=m; ++j)
				f[i][j].reset(),g[i][j].reset();
		//f[pos][i][j]:(i,j)->(mid,pos) or (mid,pos)->(i,j)
		for(int pos=1; pos<=m; ++pos) if(s[mid][pos]=='.')
		{
			for(int j=pos; j>=1&&s[mid][j]=='.'; --j)
				f[mid][j][pos]=1;
			for(int j=pos; j<=m&&s[mid][j]=='.'; ++j)
				g[mid][j][pos]=1;
		}
		for(int i=mid-1; i>=l; --i) 
			for(int j=m; j>=1; --j) 
				(s[i][j]=='.')&&(f[i][j]=f[i+1][j]|f[i][j+1],0);
		for(int i=mid+1; i<=r; ++i) 
			for(int j=1; j<=m; ++j) 
				(s[i][j]=='.')&&(g[i][j]=g[i-1][j]|g[i][j-1],0);
		for(int i:v) if(q[i].l<=mid&&q[i].r>=mid)
			{
				ans[i]|=(f[q[i].l][q[i].x]&g[q[i].r][q[i].y]).any();
			}
	}
	if(!ls.empty()) solve(l,mid-1,ls);
	if(!rs.empty()) solve(mid+1,r,rs);
	return ; 
}
signed main()
{
	vector<int> v;
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	int T=read();
	for(int i=1; i<=T; ++i)
		q[i].l=read(),q[i].x=read(),q[i].r=read(),q[i].y=read(),
		v.push_back(i);
	solve(1,n,v);
	for(int i=1; i<=T; ++i)
		puts(ans[i]?"Yes":"No");
	return 0;
}