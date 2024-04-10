// Problem: F. Mars
// Contest: Codeforces - Bubble Cup 14 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred, Div. 1)
// URL: https://codeforces.com/contest/1599/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int p=1e9+7,inv2=(p+1)>>1,inv6=(p+1)/6;
#define int long long
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
#undef int
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
gp_hash_table<int,int> mp;
int a[200003];
bool ans[200003];
struct query
{
	int bl,l,r,k,id;
	bool operator<(const query&t)const
	{
		return (bl<t.bl)||(bl==t.bl&&((bl&1)?(r<t.r):(r>t.r)));
	}
}q[200003];
int n=read(),m=read(),B=n/sqrt(m)+1;
ll s0,s1,s2;
inline void ins(int x)
{
	if(!mp[x]++)
		++s0,s1=(s1+x)%p,s2=(s2+1ll*x*x%p)%p;
}
inline void del(int x)
{
	if(!--mp[x])
		--s0,s1=(s1+p-x)%p,s2=(s2+p-1ll*x*x%p)%p;
}
inline ll PRE(ll t)
{
	return t*(t+1)%p*((t<<1)+1)%p*inv6%p;
} 
signed main()
{
	
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=m; ++i)
		q[i].l=read(),q[i].r=read(),q[i].bl=q[i].l/B,
		q[i].k=read(),q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1,l=1,r=0; i<=m; ++i)
	{
		while(r<q[i].r) ins(a[++r]);
		while(l>q[i].l) ins(a[--l]);
		while(r>q[i].r) del(a[r--]);
		while(l<q[i].l) del(a[l++]);
		if(s0==1)
		{
			ans[q[i].id]=1;
			continue;
		}
#define D d
		int D=q[i].k;
		ll mid=1ll*s1*qp(s0,p-2)%p;
		ll g=(s0-1)*inv2%p;
		ll a0=(mid+p-1ll*g*D%p)%p;
		//a0 + a0+d + a0+2d + ... + a0+(s0-1)d
		ll ss2=(a0*a0%p*s0%p+a0*d%p*s0%p*(s0-1)%p+PRE(s0-1)*d%p*d%p)%p;
		//a0^2 + 2i a0d +  i^2d^2
		ans[q[i].id]=(ss2==s2);
	}
	for(int i=1; i<=m; ++i) puts(ans[i]?"Yes":"No");
	return 0;
}