// Problem: E. Swap and Maximum Block
// Contest: Codeforces - Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1716/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ans[19][1<<18];
int n=read(),N=1<<n;
vector<int> p[1<<19],s[1<<19];
int sum[1<<19];
void solve(int l,int r,int d,int L,int x=1)
{
	p[x].resize(d),s[x].resize(d);
	if(d==1)
	{
		p[x][0]=s[x][0]=max(0ll,sum[x]=read());
		ans[0][0]=max(ans[0][0],p[x][0]);
		return ;
	}
	int mid=l+(d>>1);
	solve(l,mid,d>>1,L-1,x<<1),
	solve(mid,r,d>>1,L-1,(x<<1)+1);
	sum[x]=sum[x<<1]+sum[(x<<1)+1];
	int D=d>>1,ls=x<<1,rs=(x<<1)+1;
	assert(D+D==(int)p[x].size());
	for(int i=0; i<D; ++i)
	{
		p[x][i]=max(p[ls][i],sum[ls]+p[rs][i]);
		s[x][i]=max(s[rs][i],sum[rs]+s[ls][i]);
		ans[L][i]=max(ans[L][i],s[ls][i]+p[rs][i]);
	}
	swap(ls,rs);
	for(int i=0; i<D; ++i)
	{
		p[x][i+D]=max(p[ls][i],sum[ls]+p[rs][i]);
		s[x][i+D]=max(s[rs][i],sum[rs]+s[ls][i]);
		ans[L][i+D]=max(ans[L][i+D],s[ls][i]+p[rs][i]);
	}
	return ;
}
signed main()
{
	solve(0,N,N,n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<(1<<i); ++j)
			ans[i+1][j]=max(ans[i+1][j],ans[i][j]),
			ans[i+1][j+(1<<i)]=max(ans[i+1][j+(1<<i)],ans[i][j]);
	for(int T=read(),x=0; T--;)
		x^=(1<<read()),printf("%lld\n",ans[n][x]);
	return 0;
}