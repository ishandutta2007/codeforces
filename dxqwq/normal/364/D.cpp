// Problem: D. Ghd
// Contest: Codeforces - Codeforces Round #213 (Div. 1)
// URL: http://codeforces.com/problemset/problem/364/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1000003];
int c[1000003];
int v[1000003];
signed main()
{
	srand(1019260817);
	int n=read(),MX=(n-1)>>1;
	for(int i=1; i<=n; ++i) a[i]=read();
	random_shuffle(a+1,a+n+1);
	int ans=1;
	for(int i=1,j=1; i<=n&&j<=10; ++i)
	{
		if(a[i]<=ans) continue;
		++j;
		int X=a[i],cnt=0;
		unordered_map<int,int> mp;
		for(int t=1; t*t<=X; ++t) if(!(X%t)) 
			v[++cnt]=t,
			(t*t!=X)&&(v[++cnt]=X/t);
		sort(v+1,v+cnt+1);
		for(int i=1; i<=cnt; ++i) c[i]=0,mp[v[i]]=i;
		for(int t=1; t<=n; ++t) if(t!=i) ++c[mp[__gcd(a[t],X)]];
		int sdt=upper_bound(v+1,v+cnt+1,ans)-v;
		for(int I=sdt; I<cnt; ++I) for(int J=I+1; J<=cnt&&c[I]<MX; ++J)
		if(!(v[J]%v[I])) c[I]+=c[J]; 
		for(int t=1; t<=cnt; ++t) if(c[t]>=MX) ans=max(ans,v[t]);
	}
	printf("%lld\n",ans);
    return 0;
}