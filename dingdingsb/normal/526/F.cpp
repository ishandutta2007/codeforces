// Problem: CF526F Pudding Monsters
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF526F
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N=3e5+100;
int n,p[N];
struct SGT{
	int mn[N<<2],tag[N<<2],cnt[N<<2];
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);cnt[x]=0;
		if(mn[lc]==mn[x])cnt[x]+=cnt[lc];
		if(mn[rc]==mn[x])cnt[x]+=cnt[rc];
	}
	void pushtag(int x,int t){
		mn[x]+=t;tag[x]+=t;
	}
	void pushdown(int x){
		if(tag[x])
			pushtag(lc,tag[x]),
			pushtag(rc,tag[x]),
			tag[x]=0;
	}
	void build(int x,int l,int r){
		if(l==r)return cnt[x]=1,void();
		build(lc,l,mid);build(rc,mid+1,r);
		pushup(x);
	}
	void add(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr)return pushtag(x,val);
		if(r<ql||qr<l)return;
		pushdown(x);
		add(lc,l,mid,ql,qr,val);
		add(rc,mid+1,r,ql,qr,val);
		pushup(x);
	}
}T;
int s1[N],top1;
int s2[N],top2;
signed main(){
	read(n);T.build(1,1,n);
	for(int i=1,x,y;i<=n;i++)read(x,y),p[x]=y;
	ll res=0;
	for(int i=1;i<=n;i++){
		while(top1&&p[s1[top1]]<p[i])T.add(1,1,n,s1[top1-1]+1,s1[top1],-p[s1[top1]]),top1--;
		while(top2&&p[s2[top2]]>p[i])T.add(1,1,n,s2[top2-1]+1,s2[top2], p[s2[top2]]),top2--;
		T.add(1,1,n,1,i,-1);
		T.add(1,1,n,s1[top1]+1,i, p[i]);
		T.add(1,1,n,s2[top2]+1,i,-p[i]);
		s1[++top1]=s2[++top2]=i;
		res+=T.cnt[1];
	}
	writeln(res);
}