// Problem: A. Road to Cinema
// Contest: Codeforces - Codeforces Round #380 (Div. 1, Rated, Based on Technocup 2017 - Elimination Round 2)
// URL: https://codeforces.com/contest/737/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int c[1000003],v[1000003];
int d[1000003];
int S[1000003];
int pre[1000003];
signed main()
{
	int n=read(),m=read(),s=read(),t=read();
	for(int i=1; i<=n; ++i) c[i]=read(),v[i]=read();
	for(int i=1; i<=m; ++i) d[i]=read();
	sort(d+1,d+m+1);
	int mx=d[1];
	int M=0;
	S[++M]=d[1];
	for(int i=2; i<=m; ++i) mx=max(mx,d[i]-d[i-1]),S[++M]=d[i]-d[i-1];
	S[++M]=s-d[m];
	sort(S+1,S+M+1);
	mx=max(mx,s-d[m]);
	int ans=1e18;
	for(int i=1; i<=M; ++i) pre[i]=pre[i-1]+S[i];
	//3 5
	//7
	//full speed 3
	//3 min
	//5
	//2 full     2
	//3 slow     6
	for(int i=1; i<=n; ++i)
	{
		if(v[i]<mx) continue;
		int C=upper_bound(S+1,S+M+1,v[i]/2)-S-1;
		int Q=pre[C];
		Q-=(M-C)*v[i]-(pre[M]-pre[C]);
		Q+=(pre[M]-pre[C])*2;
		if(Q<=t)
		ans=min(ans,c[i]);
	}
	if(ans>1e15) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}