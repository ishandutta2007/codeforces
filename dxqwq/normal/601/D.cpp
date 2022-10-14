// Problem: D. Acyclic Organic Compounds
// Contest: Codeforces Round #333 (Div. 1)
// URL: https://codeforces.com/contest/601/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p1=1019260817,p2=998244353,base=131;
int qp1(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p1) if(y&1) res=res*t%p1;
	return res;
}
int qp2(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p2) if(y&1) res=res*t%p2;
	return res;
}
#define mp(x,y) make_pair(x,y)
set<pair<int,int>> ss;
char str[300003];
int mx=-1,cnt=0;
int son[300003],sz[300003];
int a[300003];
vector<int> e[300003];
void dfs(int x,int fa)
{
	sz[x]=1;
	for(int y:e[x]) if(y!=fa)
		dfs(y,x),sz[x]+=sz[y],(sz[y]>sz[son[x]])&&(son[x]=y);
	return ;
}
void add(int x,int fa,int qwq,int awa,int qwq_,int awa_,
int k,int b,int k_,int b_,set<pair<int,int>> &s)
{
	qwq=(qwq+awa*str[x])%p1,awa=awa*131%p1;
	qwq_=(qwq_+awa_*str[x])%p2,awa_=awa_*131%p2;
	s.insert(make_pair((qwq+p1-b)*qp1(k,p1-2)%p1,
	(qwq_+p2-b_)*qp2(k_,p2-2)%p2));
	for(int y:e[x]) if(y!=fa) 
		add(y,x,qwq,awa,qwq_,awa_,k,b,k_,b_,s);
	return ;
}
void solve(int x,int fa,int&k,int&b,int&k_,int&b_,set<pair<int,int>> &s)
{
	set<pair<int,int>> st;
	int tk,tb,tk_,tb_;
	for(int y:e[x]) if(y!=fa&&y!=son[x]) 
	tk=tk_=1,tb=tb_=0,solve(y,x,tk,tb,tk_,tb_,st),st.clear();
	if(son[x]) solve(son[x],x,k,b,k_,b_,s);
	//(kx+b)*131+s[x]
	b=(b*131+str[x])%p1,k=k*131%p1;
	b_=(b_*131+str[x])%p2,k_=k_*131%p2;
	s.insert(make_pair((p1+str[x]-b)*qp1(k,p1-2)%p1,
	(p2+str[x]-b_)*qp2(k_,p2-2)%p2));
	for(int y:e[x]) if(y!=fa&&y!=son[x]) 
	add(y,x,str[x],131,str[x],131,k,b,k_,b_,s);
	a[x]+=(int)s.size();
	if(a[x]>mx) mx=a[x],cnt=1;
	else if(a[x]==mx) ++cnt; 
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	scanf("%s",str+1);
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	set<pair<int,int>> s;
	int K=1,B=0,KK=1,BB=0;
	dfs(1,1),solve(1,1,K,B,KK,BB,s);
	printf("%lld\n%lld\n",mx,cnt);
	return 0;
}