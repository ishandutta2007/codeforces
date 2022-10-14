// Problem: F2. Alice and Recoloring 2
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/F2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
struct iakioi
{
	vector<int> a[503],b[503];
	bool visa[503],now;
	int cona[503],conb[503];
	bool dfs(int x)
	{
		now^=1;
		if(visa[x]) return false;
		visa[x]=1;
		int sz=a[x].size();
		for(int i=0; i<sz; i++) if(conb[a[x][i]]==0)
		{
			cona[x]=a[x][i];
			conb[a[x][i]]=x;
			return true;
		} 
		else if(conb[a[x][i]]!=x) if(dfs(conb[a[x][i]])) 
		{
			cona[x]=a[x][i];
			conb[a[x][i]]=x;
			return true;
		}
		return false;
	}
	void addedge(int u,int v)
	{
		a[u].push_back(v);
		b[v].push_back(u);
	}
	int main(int n,int m)
	{
		int ans=0;
		for(int i=1; i<=n; i++) 
		{
			memset(visa,0,sizeof(visa));
			now=0;//Left
			if(dfs(i)) ++ans;
		}
		return ans;
	}
}F;
char s[503][503];
bool a[503][503];
bool b[503][503];
bool f[503],g[503];
bool ovo[503];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) a[i][j]=(s[i][j]=='B');
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) b[i][j]=(a[i][j]!=a[i][j-1]);
	for(int i=n; i>=1; --i)
		for(int j=1; j<=m; ++j) b[i][j]=(b[i][j]!=b[i-1][j]); 
	int c=b[1][1];
	int ans=0;
	for(int i=2; i<=n; ++i)
		for(int j=2; j<=m; ++j)
			ans+=2*b[i][j];
	for(int i=2; i<=n; ++i) f[i]^=b[i][1],c^=b[i][1];
	for(int j=2; j<=m; ++j) g[j]^=b[1][j],c^=b[1][j];
	
	// for(int i=1; i<=n; ++i,puts(""))
		// for(int j=1; j<=m; ++j) printf("%d",b[i][j]);
	// printf("%d\n",c);
	// for(int i=1; i<=n; ++i) printf("%d",f[i]);
	// puts("");
	// for(int i=1; i<=m; ++i) printf("%d",g[i]);
	// puts("");
	int A=0,B=0;
	for(int i=2; i<=n; ++i)
	{
		bool tag=0;
		for(int j=2; j<=m; ++j) if(b[i][j])
			--ans,g[j]^=1,f[i]^=1,c^=1;
		if(f[i]) ++ans;
	}
	for(int j=1; j<=m; ++j) ans+=g[j];
	for(int i=2; i<=n; ++i)
		for(int j=2; j<=m; ++j)
			if(f[i]&&g[j]&&b[i][j]) F.addedge(i,j);
	int C=F.main(n,m);
	ans+=min(c,(c^(C&1))-C);
	printf("%d\n",ans);
	return 0;
}