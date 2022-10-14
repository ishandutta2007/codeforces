// Problem: A. Weights
// Contest: Codeforces - Bubble Cup 14 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred, Div. 1)
// URL: https://codeforces.com/contest/1599/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003];
char s[1000003],t[1000003];
void print(int x)
{
	if(x>0) printf("%lld L\n",x);
	else printf("%lld R\n",-x);
	return;
}
int L=1,R,rev=0;
#define pre b
int gpre(int x)
{
	if(rev)
		return pre[R]-pre[R-x];
	else
		return pre[L+x-1]-pre[L-1];
}
int ans[1000003];
int cur=0;
void RED()
{
	if(rev) ans[cur--]=a[L],++L;
	else ans[cur--]=a[R],--R;
}
signed main()
{
	int n=read();
	R=n;cur=n;
	for(int i=1; i<=n; ++i) a[i]=read();
	sort(a+1,a+n+1);
	scanf("%s",s+1);
	if(s[n]=='L')
	{
		//1 -2 3 -4
		//L R L R
		for(int i=(n+1)&1; i<=n; i+=2) a[i]=-a[i]; 
		for(int i=1; i<=n; ++i) b[i]=b[i-1]+a[i]; 
		for(int i=n-1; i>=1; --i,RED()) if((s[i]=='L')!=(gpre(i)>0))
		{
			rev^=1;
			//reverse(a+1,a+i+2);
		}
	}
	else
	{
		for(int i=n&1; i<=n; i+=2) a[i]=-a[i]; 
		for(int i=1; i<=n; ++i) b[i]=b[i-1]+a[i]; 
		for(int i=n-1; i>=1; --i,RED()) if((s[i]=='L')!=(gpre(i)>0))
		{
			rev^=1;
			//reverse(a+1,a+i+2);
		}
	}
	ans[1]=a[L];
	for(int i=1; i<=n; ++i) print(ans[i]); 
	return 0;
}