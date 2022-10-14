// Problem: C. Extreme Extension
// Contest: Codeforces Round #752 (Div. 1)
// URL: https://codeforces.com/contest/1603/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
const int p=998244353;
int a[100003];
int f[100003];
bool vf[100003];
int pos[100003],pc;
int tf[100003];
int tp[100003],tpc;
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		int ans=0;
		for(int i=n; i>=1; --i)
		{
			for(int iii=1; iii<=pc; ++iii)
			{
				int j=pos[iii],A=a[i]/(((a[i]-1)/j)+1);
				(ans+=f[j]*((a[i]-1)/j)%p*i)%=p,
				(!vf[A])&&(vf[A]=1,tp[++tpc]=A),
				(tf[A]+=f[j])%=p,f[j]=0;
			}
			(!vf[a[i]])&&(vf[a[i]]=1,tp[++tpc]=a[i]),++tf[a[i]];
			pc=tpc;
			for(int i=1; i<=tpc; ++i) 
			pos[i]=tp[i],f[tp[i]]=tf[tp[i]],tf[tp[i]]=0,vf[tp[i]]=0;
			tpc=0;
		}
		for(int i=1; i<=pc; ++i) f[pos[i]]=0;
		pc=0;
		printf("%lld\n",ans);
	}
	return 0;
}