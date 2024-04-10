// Problem: C. Omkar and Determination
// Contest: Codeforces - Codeforces Round #749 (Div. 1 + Div. 2, based on Technocup 2022 Elimination Round 1)
// URL: https://codeforces.com/contest/1586/problem/C
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
struct stmax
{
	int n;
	int a[1000003],st[1000003][21],l2[1000003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=20; i++) 
		st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main(int N)
	{
		n=N;
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}st;
char s[1000003];
vector<bool> a[1000003];
int f[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=0; i<=n+1; ++i)
		a[i].resize(m+2);
	for(int i=1; i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j) a[i][j]=(s[j]=='.');
	}
	for(int i=2; i<=n; ++i)
	{
		for(int j=2; j<=m; ++j)
			if(!a[i-1][j]&&!a[i][j-1])
				++f[j];
	}
	for(int j=2; j<=m; ++j) f[j]+=f[j-1];
	for(int T=read();T--;)
	{
		int l=read(),r=read();
		if(f[l]==f[r]) puts("YES");
		else puts("NO");
	}
	return 0;
}