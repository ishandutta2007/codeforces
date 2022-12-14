#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define pb push_back
#define mid ((l+r)>>1)
#define fi first
#define se second
#define ull unsigned ll
const int N=2e5+5;
int n,m,q,tot,las,rt[N];pair<int,int>a[N];
struct did{ull mx:18,ls:23,rs:23;}t[N*40];
in int read() {int x;scanf("%d",&x);return x;}
int ins(int p,int l,int r,int L,int R)
{
	if(l==r) return p+1;int o=++tot;t[o]=t[p];if(L<=l&&r<=R) return t[o].mx++,o;
	int T=t[o].mx-max(l==mid?t[o].ls:t[t[o].ls].mx,mid+1==r?t[o].rs:t[t[o].rs].mx);
	if(L<=mid) t[o].ls=ins(t[p].ls,l,mid,L,R);if(R>mid) t[o].rs=ins(t[p].rs,mid+1,r,L,R);
	return t[o].mx=T+max(l==mid?t[o].ls:t[t[o].ls].mx,mid+1==r?t[o].rs:t[t[o].rs].mx),o;
}
int ask(int p,int l,int r,int L,int R)
{
	if(l==r) return p;if(L<=l&&r<=R) return t[p].mx;
	int ans=0,T=t[p].mx-max(l==mid?t[p].ls:t[t[p].ls].mx,mid+1==r?t[p].rs:t[t[p].rs].mx);
	if(L<=mid) ans=max(ans,ask(t[p].ls,l,mid,L,R));if(R>mid) ans=max(ans,ask(t[p].rs,mid+1,r,L,R));
	return ans+T; 
}
int main()
{
	n=read(),m=read();for(int i=1;i<=n;i++) a[i]={-read(),i};sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) rt[i]=ins(rt[i-1],1,n-m+1,max(1,a[i].se-m+1),min(a[i].se,n-m+1));q=read();
	while(q--)
	{
		int l=read(),r=read(),x=read()^las,o=upper_bound(a+1,a+n+1,make_pair(-x,n+1))-a-1;
		printf("%d\n",las=m-ask(rt[o],1,n-m+1,l,r));
	}
	return 0;
}
//Author: disangan233