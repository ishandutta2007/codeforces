// Problem: F. Almost Sorted
// Contest: Codeforces - Codeforces Round #823 (Div. 2)
// URL: https://codeforces.com/contest/1730/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
map<vector<int>,int> mp;
int F[22003][9];
int sz[22003],S[22003];
int cnt,a[5003],ss,ans;
int tr[22003][9];
short cml_f[22003],cml_g[22003];
short *f=cml_f,*g=cml_g;
vector<int> T(vector<int> &G)
{
	if(G.empty()) return G;
	for(auto it=next(G.begin()),lst=G.begin(); ; ++it)
	{
		if(it==G.end())
		{
			sort(next(lst),it);
			return G;
		}
		if((*it)>(*lst)) 
		sort(next(lst),it),lst=it;
	}
	return {5,2,8,2,2,1};
}
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) a[read()]=i;
	mp[vector<int>()]=1,cnt=1;
	vector<int> ff(m);
	for(int j=0; j<m; ++j)
		ff[j]=j;
	do
	{
		vector<int> L;
		for(int j=0; j<m; ++j)
		{
			L.push_back(ff[j]);
			vector<int> G=T(L);
			if(!mp[G])
			{
				mp[G]=++cnt,S[cnt]=G.size();
				for(int k=0; k<S[cnt]; ++k)
					F[cnt][k]=G[k];
			}
		}
	}
	while(next_permutation(ff.begin(),ff.end()));
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<=n; ++j)
			if(a[i]>a[j]) ++ss;
	for(auto it:mp)
	{
		vector<int> f=it.first;
		int i=f.size();
		int id=it.second,pre=-1;
		for(int j=0; j<=i; ++j) if(j==0||f[j-1]>pre)
		{
			vector<int> g=f;
			g.insert(g.begin()+j,-1);
			for(int pos=0; pos<=i; ++pos)
			{
				if(++g[pos]==m)
				{
					g.erase(g.begin()+pos,g.end());
					break;
				}
			}
			tr[id][sz[id]++]=mp[T(g)];
			if(j) pre=f[j-1];
		};
	}
	memset(f,0x3f,sizeof(cml_f)),f[1]=0;
	for(int i=n; i>=1; --i)
	{
		swap(f,g),memset(f,0x3f,sizeof(cml_f));
		for(int j=1; j<=cnt; ++j) if(g[j]!=0x3f3f3f3f)
		{
			short X=0,Y=0;
			int V=-1,I=0,SZ=S[j];
			for(int k=0; k<SZ; ++k)
			{
				if(F[j][k]>V) 
					f[tr[j][I]]=min(f[tr[j][I]],(short)(g[j]+Y)),
					++I,Y=X,V=F[j][k];
				if(a[i]>a[F[j][k]+i+1]) --X,--Y;
				else ++X;
			}
			f[tr[j][I]]=min(f[tr[j][I]],(short)(g[j]+Y));
		}
	}
	int ans=0;
	for(int i=1; i<=cnt; ++i) ans=min(ans,(int)f[i]);
	printf("%d\n",ans+ss);
	return 0;
}