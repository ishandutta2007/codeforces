// Problem: A. Stairs and Elevators
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int a[1000003],b[1000003];
signed main()
{
	int n=read(),m=read();
	int N=read(),M=read();
	int v=read();
	for(int i=1; i<=N; ++i) a[i]=read();
	a[++N]=1e12;
	a[++N]=-1e12;
	sort(a+1,a+N+1);
	for(int i=1; i<=M; ++i) b[i]=read();
	b[++M]=1e12;
	b[++M]=-1e12;
	sort(b+1,b+M+1);
	for(int T=read();T--;)
	{
		int D1=read();
		int X=read();
		int D=0;
		int D2=read();
		int Y=read();
		int ans=1e18;
		D=abs(D1-D2);
		if(X>Y) swap(X,Y);
		if(D==0)
		{
			printf("%lld\n",Y-X);
			continue;
		}
		//go by stairs
		int s=*lower_bound(a+1,a+N+1,X);
		if(s<=Y) ans=min(ans,D+Y-X);
		else ans=min(ans,D+s+s-X-Y);
		auto I=lower_bound(a+1,a+N+1,X);
		--I;
		s=*I;
		ans=min(ans,D+X+Y-s-s);
		
		D=(D-1)/v+1;
		
		
		s=*lower_bound(b+1,b+M+1,X);
		if(s<=Y) ans=min(ans,D+Y-X);
		else ans=min(ans,D+s+s-X-Y);
		
		I=lower_bound(b+1,b+M+1,X);
		--I;
		s=*I;
		ans=min(ans,D+X+Y-s-s);
		printf("%lld\n",ans);
	}
	return 0;
}