// Problem: F. Classical?
// Contest: Codeforces - Codeforces Round #613 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1285/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int n=100000;
vector<int> d[100003];
int a[100003],c[100003];
int prime[100003],mu[100003],cnt;
bool vis[100003];
void upd(int x,int k)
{
	for(int i:d[x]) c[i]+=k;
	return ;
}
int chk(int x)
{
	int r=0;
	for(int i:d[x]) r+=c[i]*mu[i];
	return r;
}
signed main()
{
	ll ans=1;
	stack<int> stk;
	mu[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(!vis[i]) prime[++cnt]=i,mu[i]=-1;
		for(int j=1; j<=cnt&&i*prime[j]<=n; ++j)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]) mu[i*prime[j]]=-mu[i];
			else break;
		}
	}
	for(int T=read(); T--;) a[read()]=1;
	for(int i=1; i<=n; ++i)
		for(int j=1; i*j<=n; ++j)
			d[i*j].push_back(i),a[i]|=a[i*j];
	for(int i=n; i>=1; --i) if(a[i]) 
	{
		// printf("%d\n",i);
		while(chk(i))
		{
			int x=stk.top();
			// printf("%d %d\n",x,i);
			if(__gcd(x,i)==1) ans=max(ans,1ll*x*i);
			upd(x,-1),stk.pop();
		}
		upd(i,1),stk.push(i);
	}
	printf("%lld\n",ans);
	return 0;
}