// Problem: D. Felicity's Big Secret Revealed
// Contest: Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/757/problem/D
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
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int f[76][1<<20];
const int N=1<<20;
char s[103];
int trans(int L,int R)
{
	int r=0;
	for(int i=L; i<=R; ++i)
	{
		r<<=1;
		if(s[i]=='1') ++r;
		if(r>20) return 0;
	}
	return r;
}
signed main()
{
	int n=read();
	scanf("%s",s+1);
	for(int i=0; i<n; ++i)
	{
		f[i][0]=(f[i][0]+1)%p;
		for(int j=0; j<N; ++j)
			if(f[i][j])
				for(int k=i+1; k<=n; ++k)
				{
					int d=trans(i+1,k)-1;
					if(d==-1) continue;
					d=1<<d;
					f[k][j|d]=(f[k][j|d]+f[i][j])%p;
				}
	}
	int ans=0;
	for(int t=1; t<=n; ++t)
	for(int i=1; i<N; ++i)
		if((i&(i+1))==0)
			ans=(ans+f[t][i])%p;
	printf("%d\n",ans);
	return 0;
}