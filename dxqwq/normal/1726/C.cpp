// Problem: C. Jatayu's Balanced Bracket Sequence
// Contest: Codeforces Round #819 (Div. 1 + Div. 2) and Grimoire of Code Annual Contest 2022
// URL: https://codeforces.com/contest/1726/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int c,n;
char s[1000003];
int fa[1000003];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	if(x==0||y==0) return;
	x=find(x);
	y=find(y);
	if(x!=y) fa[x]=y;
}
pair<int,int> dfs()
{
	int t=++c,fi=0;
	assert(s[c]=='(');
	while(c<n&&s[c+1]=='(')
	{
		pair<int,int> r=dfs();
		if(!fi) fi=r.first;
		merge(fi,r.first),merge(fi,r.second);
	}
	++c;
	return make_pair(t,c);
}
signed main()
{
	s[0]='(';
	for(int T=read();T--;)
	{
		n=read()*2;
		s[n+1]=')';
		c=-1;
		scanf("%s",s+1);
		for(int i=1; i<=n; ++i) fa[i]=i;
		dfs();
		int ans=0;
		for(int i=1; i<=n; ++i) 
			if(find(i)==i) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}