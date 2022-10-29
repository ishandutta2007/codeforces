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

const int N=3e5+5;
int n,m,a[N],maxn[N],cnt1,minn[N],cnt2,pre[N],nw;ll Ans[N];
struct question{
	int l,r,id;
	inline bool operator < (const question &o)const{return r<o.r;}
}q[N];

struct SGT{
	#define xl (x<<1)
	#define xr (x<<1|1)
	#define mid ((l+r)>>1)
	int sum[N<<2],tag[N<<2],ans[N<<2],tim[N<<2],lazy[N<<2];ll tt[N<<2];
	inline void pushup(int x){sum[x]=min(sum[xl],sum[xr]);ans[x]=ans[xl]*(sum[xl]==sum[x])+ans[xr]*(sum[xr]==sum[x]);tt[x]=tt[xl]+tt[xr];}
	inline void build(int x,int l,int r){
		if(l==r){sum[x]=tag[x]=tt[x]=0;ans[x]=1;return ;}
		build(xl,l,mid);build(xr,mid+1,r);pushup(x);
	}
	inline void pushdown(int x){if(tag[x]) sum[xl]+=tag[x],sum[xr]+=tag[x],tag[xl]+=tag[x],tag[xr]+=tag[x],tag[x]=0;if(lazy[x]){if(sum[x]==sum[xl]) tt[xl]+=1ll*ans[xl]*lazy[x],lazy[xl]+=lazy[x];if(sum[x]==sum[xr]) tt[xr]+=1ll*ans[xr]*lazy[x],lazy[xr]+=lazy[x];lazy[x]=0;}}
	inline void modify(int x,int l,int r,int L,int R,int k){
		if(L<=l&&r<=R){sum[x]+=k;tag[x]+=k;return ;}
		pushdown(x);
		if(L<=mid) modify(xl,l,mid,L,R,k);
		if(R>mid) modify(xr,mid+1,r,L,R,k);
		pushup(x); 
	}
	inline void push(){tt[1]+=1ll*ans[1];++lazy[1];}
	inline ll query(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R) return tt[x];
		pushdown(x);
		ll res=0;
		if(L<=mid) res+=query(xl,l,mid,L,R);
		if(R>mid) res+=query(xr,mid+1,r,L,R);
		return res;
	}
	#undef xl
	#undef xr
	#undef mid
}T;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);for(re i=1;i<=n;++i) rd(a[i]);
	rd(m);for(re i=1;i<=m;++i) rd(q[i].l),rd(q[i].r),q[i].id=i;sort(q+1,q+m+1);
	T.build(1,1,n);
	for(re i=1;i<=m;++i){
		while(nw<q[i].r){
			++nw;
			while(cnt1&&a[maxn[cnt1]]<a[nw]) T.modify(1,1,n,maxn[cnt1-1]+1,maxn[cnt1],-a[maxn[cnt1]]),--cnt1;
			while(cnt2&&a[minn[cnt2]]>a[nw]) T.modify(1,1,n,minn[cnt2-1]+1,minn[cnt2],a[minn[cnt2]]),--cnt2;
			T.modify(1,1,n,pre[a[nw]]+1,nw,-1);pre[a[nw]]=nw;
			maxn[++cnt1]=minn[++cnt2]=nw;
			T.modify(1,1,n,maxn[cnt1-1]+1,nw,a[nw]);T.modify(1,1,n,minn[cnt2-1]+1,nw,-a[nw]);
			T.push();
	//		cout<<"--------------\n"<<nw<<endl;
	//		for(re j=1;j<=nw;++j) cout<<T.query(1,1,n,j,j)<<' ';cout<<endl;
		}
		Ans[q[i].id]=T.query(1,1,n,q[i].l,q[i].r);
	}
	for(re i=1;i<=m;++i) wr(Ans[i]),puts("");
	return 0;
}

// ---------- Main ---------- //