// Problem: CF446C DZY Loves Fibonacci Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF446C
// Memory Limit: 250 MB
// Time Limit: 4000 ms
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
const int mod=1e9+9;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
const int N=3e5+100;
int n,m;mint a[N];
mint f[N];
mint f1[N],s1[N];
mint f2[N],s2[N];
struct node{
	mint taga,tagb;
	int len,l,r;
	mint sum;
	node*lc,*rc;
	node(int l,int r):l(l),r(r){
		len=r-l+1;taga=tagb=0;
		if(l==r){sum=a[l];return;}
		lc=new node(l,mid);
		rc=new node(mid+1,r);
		pushup();
	}
	void pushtag(mint v1,mint v2){
		taga+=v1,tagb+=v2;
		sum+=v1*s1[len]+v2*s2[len];
	}
	void pushdown(){
		lc->pushtag(taga,tagb);
		rc->pushtag(
		    taga*f1[lc->len+1]+tagb*f2[lc->len+1],
			taga*f1[lc->len+2]+tagb*f2[lc->len+2]);
		taga=tagb=0;
	}
	void pushup(){sum=lc->sum+rc->sum;}
	void upd(int ql,int qr){
		if(ql<=l&&r<=qr)return pushtag(f[l-ql+1],f[l-ql+2]);
		if(r<ql||qr<l)return;
		pushdown();
		lc->upd(ql,qr);
		rc->upd(ql,qr);
		pushup();
	}
	mint qry(int ql,int qr){
		if(ql<=l&&r<=qr)return sum;
		if(r<ql||qr<l)return 0;
		pushdown();
		return lc->qry(ql,qr)+rc->qry(ql,qr);
	}
};
signed main(){
	f[1]=f[2]=1;for(int i=3;i<N;i++)f[i]=f[i-1]+f[i-2];
	f1[1]=1,f1[2]=0;for(int i=3;i<N;i++)f1[i]=f1[i-1]+f1[i-2];
	for(int i=1;i<N;i++)s1[i]=s1[i-1]+f1[i];
	f2[1]=0,f2[2]=1;for(int i=3;i<N;i++)f2[i]=f2[i-1]+f2[i-2];
	for(int i=1;i<N;i++)s2[i]=s2[i-1]+f2[i];
	read(n,m);for(int i=1;i<=n;i++)read(a[i]);
	node root(1,n);
	while(m--){
		int op,l,r;read(op,l,r);
		if(op==1)root.upd(l,r);
		else writeln(root.qry(l,r).x);
	}
}