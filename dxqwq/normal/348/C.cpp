// Problem: C. Subset Sums
// Contest: Codeforces - Codeforces Round #202 (Div. 1)
// URL: https://codeforces.com/problemset/problem/348/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int B=330;
bool c[100003];
int id[330],cnt;
int u[100003][330];
ll a[100003],ans[100003],tag[100003];
vector<int> v[100003];
signed main()
{
	int n=read(),m=read(),q=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=m; ++i)
	{
		v[i].resize(read());
		for(int &j:v[i]) j=read();
		if((int)v[i].size()>B) 
		{
			id[++cnt]=i;
			for(int &j:v[i]) ans[i]+=a[j];
		}
	}
	for(int i=1; i<=cnt; ++i)
	{
		for(int j:v[id[i]]) c[j]=1;
		for(int j=1; j<=m; ++j)
			for(int k:v[j]) u[j][i]+=c[k];
		for(int j:v[id[i]]) c[j]=0;	
	}
	char op;
	for(int x,k; q--;)
	{
		op=getchar();
		while(op!='?'&&op!='+') op=getchar();	
		if(op=='?')
		{
			x=read();
			if((int)v[x].size()<=B)
			{
				ll sum=0;
				for(int i=1; i<=cnt; ++i)
					sum+=1ll*u[x][i]*tag[id[i]];
				for(int i:v[x]) sum+=a[i];
				printf("%lld\n",sum);
			}
			else printf("%lld\n",ans[x]);
		}
		else
		{
			x=read(),k=read();
			for(int i=1; i<=cnt; ++i)
				ans[id[i]]+=1ll*u[x][i]*k;
			if((int)v[x].size()<=B)
				for(int j:v[x]) a[j]+=k;
			else tag[x]+=k;
		}
	}
	return 0;
}