// Problem: E. Ciel and Gondolas
// Contest: Codeforces - Codeforces Round #190 (Div. 1)
// URL: https://codeforces.com/problemset/problem/321/E
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int a[4003][4003],f[4003],g[4003],stk[4003],pos[4003],top;
pair<int,int> F(int j,int i)
{return make_pair(f[j]+a[i][i]+a[j][j]-a[i][j]*2,-g[j]);}
signed main()
{
	int n=read(),k=read();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]=read();
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]+=a[i][j-1];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j]+=a[i-1][j];	
	int l=-1,r=2e9,lst=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		stk[top=1]=0,pos[1]=1;
		for(int i=1; i<=n; ++i)
		{
			int d=upper_bound(pos+1,pos+top+1,i)-pos-1,j=stk[d];
			f[i]=f[j]+a[i][i]+a[j][j]-a[i][j]*2+mid,g[i]=g[j]+1;
			if(i==n||F(stk[top],n)<=F(i,n)) continue;
			while(top&&i<pos[top]&&
			F(stk[top],pos[top])>F(i,pos[top])) --top;
			int l=max(pos[top],i+1),r=n,res=n+1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(F(stk[top],mid)>F(i,mid)) res=mid,r=mid-1;
				else l=mid+1;
			}
			stk[++top]=i,pos[top]=res;
		}
		f[n]-=mid*g[n];
		if(g[n]==k) printf("%lld\n",f[n]>>1),exit(0);
		else if(g[n]>k) lst=f[n]-mid*(k-g[n]),l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",lst>>1);
	return 0;
}