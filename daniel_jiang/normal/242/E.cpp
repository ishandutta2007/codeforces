// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=1e5+5,V=20;
int n,a[N],k,m;

struct SGT{
	#define mid ((l+r)>>1)
	#define xl (x<<1)
	#define xr (x<<1|1)
	int sum[N<<2],tag[N<<2];
	inline void pushup(int x){sum[x]=sum[xl]+sum[xr];}
	inline void build(int x,int l,int r){
		if(l==r){sum[x]=(a[l]>>k)&1;return ;}
		build(xl,l,mid);build(xr,mid+1,r);
		pushup(x);
	}
	inline void pushdown(int x,int l,int r){
		if(tag[x]){
			sum[xl]=mid-l+1-sum[xl];sum[xr]=r-mid-sum[xr];
			tag[xl]^=1;tag[xr]^=1;tag[x]=0;
		}
	}
	inline void modify(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R){sum[x]=r-l+1-sum[x];tag[x]^=1;return ;}
		pushdown(x,l,r);
		if(mid>=L) modify(xl,l,mid,L,R);
		if(mid<R) modify(xr,mid+1,r,L,R);
		pushup(x);
	}
	inline int query(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R) return sum[x];
		pushdown(x,l,r);int res=0;
		if(mid>=L) res+=query(xl,l,mid,L,R);
		if(mid<R) res+=query(xr,mid+1,r,L,R);
		return res;
	}
	#undef mid
	#undef xl
	#undef xr
}T[21];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]);
	for(k=0;k<=V;++k) T[k].build(1,1,n);
	rd(m);
	for(re i=1;i<=m;++i){
		int op;rd(op);
		if(op==1){
			int l,r;rd(l);rd(r);
			ll ans=0;
			for(k=0;k<=V;++k) ans+=(1ll<<k)*T[k].query(1,1,n,l,r);
			wr(ans);puts("");
		}
		else{
			int l,r,x;rd(l);rd(r);rd(x);
			for(k=0;k<=V;++k)
				if((x>>k)&1) T[k].modify(1,1,n,l,r);
		}
	}
	return 0;
}

// ---------- Main ---------- //