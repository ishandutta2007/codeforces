#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=1000005;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n,m,q,ty,x,d;
long long a[N],b[N];
long long mn[N*4],tree[N*4],lazy[N*4],tree2[N*4],lazy2[N*4];
void pushup(int i,int l,int r){
	mn[i]=min(mn[i<<1],mn[i<<1|1])+lazy2[i];
	tree2[i]=tree2[i<<1]+tree2[i<<1|1]+lazy2[i]*(l+r)*(r-l+1)/2;
	tree[i]=tree[i<<1]+tree[i<<1|1]+lazy[i]*(r-l+1);
}
void modify(int i,int l,int r,int ll,int rr,int d){
	if(l>=ll&&r<=rr){
		tree2[i]+=1ll*d*(l+r)*(r-l+1)/2;
		lazy2[i]+=d;
		mn[i]+=d;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,d);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,d);
	pushup(i,l,r);
}
void modify2(int i,int l,int r,int ll,int rr,long long d){
	if(l>=ll&&r<=rr){
		tree[i]+=d*(r-l+1);
		lazy[i]+=d;
		return;
	}
	int mid=l+r>>1;
	if(mid>=ll)
		modify2(i<<1,l,mid,ll,rr,d);
	if(mid<rr)
		modify2(i<<1|1,mid+1,r,ll,rr,d);
	pushup(i,l,r);
}
int Query(int i,int l,int r,long long d,long long x){
	if(l==r){
		if(d<x+mn[i])
			return l-1;
		return l;
	}
	int mid=l+r>>1;
	if(mn[i<<1|1]+x+lazy2[i]>=d)
		return Query(i<<1,l,mid,d,x+lazy2[i]);
	else
		return Query(i<<1|1,mid+1,r,d,x+lazy2[i]);
}
long long Query2(int i,int l,int r,int ll,int rr){
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1;
	long long ans=0;
	if(mid>=ll)
		ans+=Query2(i<<1,l,mid,ll,rr);
	if(mid<rr)
		ans+=Query2(i<<1|1,mid+1,r,ll,rr);
	int ul=max(l,ll),ur=min(r,rr);
	return ans+lazy[i]*(ur-ul+1);
}
long long Query3(int i,int l,int r,int ll,int rr){
	if(l>=ll&&r<=rr)
		return tree2[i];
	int mid=l+r>>1;
	long long ans=0;
	if(mid>=ll)
		ans+=Query3(i<<1,l,mid,ll,rr);
	if(mid<rr)
		ans+=Query3(i<<1|1,mid+1,r,ll,rr);
	int ul=max(l,ll),ur=min(r,rr);
	return ans+lazy2[i]*(ul+ur)*(ur-ul+1)/2;
}
void Build(int i,int l,int r){
	if(l==r){
		tree2[i]=b[l];
		mn[i]=b[l]-b[l-1];
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	pushup(i,l,r);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	gi(n),gi(m),gi(q);
	for(int i=1;i<=n;++i)
		gi(a[i]);
	for(int i=1;i<=m;++i)
		gi(b[i]);
	Build(1,1,m);
	// cout<<tree2[1]<<endl;
	while(q--){
		gi(ty),gi(x),gi(d);
		if(ty==1)
			for(int i=n-x+1;i<=n;++i)
				a[i]+=1ll*(i-(n-x))*d;
		if(ty==2){
			modify(1,1,m,m-x+1,m,d);
			modify2(1,1,m,m-x+1,m,-1ll*d*(m-x));
		}
		long long ans=0;
		int las=1;
		for(int i=2;i<=n;++i){
			int x=Query(1,1,m,a[i]-a[i-1],0);
			x=max(x,1);
			ans+=Query3(1,1,m,las,x)+Query2(1,1,m,las,x)+a[i-1]*(x-las+1);
			// cout<<a[i-1]*(x-las+1)<<' ';
			// cout<<las<<' '<<x<<' '<<Query3(1,1,m,las,x)+Query2(1,1,m,las,x)<<endl;
			// cout<<a[i-1]<<' ';
			las=x;
		}
		ans+=a[n]*(m-las+1)+Query3(1,1,m,las,m)+Query2(1,1,m,las,m);
		printf("%lld\n",ans);
	}
}