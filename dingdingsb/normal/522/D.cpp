// Problem: CF522D Closest Equals
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF522D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=5e5+100;
int n,m,a[N];
int ans[N];
struct SGT{
	int mn[N<<2];
	void build(int x,int l,int r){
		mn[x]=0x3f3f3f3f;
		if(l==r)return;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void upd(int x,int l,int r,int pos,int val){
		chkmn(mn[x],val);
		if(l==r)return;
		if(pos<=mid)upd(lc,l,mid,pos,val);
		else upd(rc,mid+1,r,pos,val);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(r<ql||qr<l)return 0x3f3f3f3f;
		return min(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T;
vector<pair<int,int>>q[N];
map<int,int>lst;
signed main(){
	read(n,m);T.build(1,1,n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1,l,r;i<=m;i++)read(l,r),q[l].pb(mp(r,i));
	for(int i=n;i;i--){
		if(lst[a[i]])T.upd(1,1,n,lst[a[i]],lst[a[i]]-i);lst[a[i]]=i;
		for(auto Q:q[i])ans[Q.se]=T.qry(1,1,n,i,Q.fi);
	}
	for(int i=1;i<=m;i++)
		writeln(ans[i]>n?-1:ans[i]);
}