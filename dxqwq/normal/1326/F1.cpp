// Problem: F2. Wise Men (Hard Version)
// Contest: Codeforces - Codeforces Global Round 7
// URL: https://codeforces.com/problemset/problem/1326/F2
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
char s[23][23];
map<vector<int>,int> mp;
int f[1<<18],g[18][1<<18],h[19][1<<18],tmp[1<<18];
void FWT_OR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				F[i+j+k]+=F[i+k];
}
void FWT_IOR(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				F[i+j+k]-=F[i+k];
}
void FWT_IAND(int*F,int n)
{
	for(int w=2,j=1; w<=n; w<<=1,j<<=1)
		for(int i=0; i<n; i+=w)
			for(int k=0; k<j; ++k)
				F[i+k]-=F[i+j+k];
}
signed main()
{
	int n=read(),N=1<<n,M=1<<(n-1);
	for(int i=0; i<n; ++i) scanf("%s",s[i]);
	for(int i=0; i<n; ++i) g[i][1<<i]=1;
	for(int i=1; i+1<N; ++i)
		for(int j=0; j<n; ++j) if((i>>j)&1)
			for(int k=0; k<n; ++k) if(!((i>>k)&1)&&s[j][k]=='1')
				g[k][i+(1<<k)]+=g[j][i];
	for(int i=1; i<N; ++i)
		for(int j=0; j<n; ++j) if((i>>j)&1)
			h[__builtin_popcount(i)][i]+=g[j][i];
	for(int i=1; i<=n; ++i) FWT_OR(h[i],N);
	for(int i=0; i<M; ++i)
	{
		vector<int> t;
		for(int j=0,v=1; j<n; ++j)
			if((i>>j)&1) ++v;
			else t.push_back(v),v=1;
		sort(t.begin(),t.end());
		if(mp.find(t)==mp.end())
		{
			for(int i=0; i<N; ++i) tmp[i]=1;
			for(int i:t)
				for(int j=0; j<N; ++j) tmp[j]*=h[i][j];
			FWT_IOR(tmp,N),mp[t]=tmp[N-1];
		}
		f[i]=mp[t];
	}
	FWT_IAND(f,M);
	for(int i=0; i<M; ++i) printf("%lld ",f[i]);
	puts("");
	return 0;
}