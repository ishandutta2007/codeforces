#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2e5+11, M = 6*N*40, inf = 0x3f3f3f3f;
int n,a[N],pos[N];set<int>p0;

int lzy[M],lc[M],rc[M];ll ans[M];int tot;
struct yzryzr{
	vector<Pii>seg,tim;
	Vi rt;
	void ins(int l, int r, int t){
		seg.pb(mp(l,r));tim.pb(mp(t,inf));
	}
	void ins(int &k, int K, int l, int r, int x, int L, int R){
		k=++tot;lc[k]=lc[K],rc[k]=rc[K];ans[k]=ans[K];lzy[k]=lzy[K];
		if(l==L&&r==R){lzy[k]+=x;ans[k]+=1ll*x*(R-L+1);return;}
		int mid=(L+R)>>1;
		if(r<=mid)ins(lc[k],lc[K],l,r,x,L,mid);
		else if(l>mid)ins(rc[k],rc[K],l,r,x,mid+1,R);
		else ins(lc[k],lc[K],l,mid,x,L,mid),ins(rc[k],rc[K],mid+1,r,x,mid+1,R);
		ans[k]=ans[lc[k]]+ans[rc[k]];
	}
	ll qry(int k, int l, int r, int L, int R){
		if(l==L&&r==R)return ans[k];
		int mid=(L+R)>>1;ll res=0;
		if(r<=mid)res=qry(lc[k],l,r,L,mid);
		else if(l>mid)res=qry(rc[k],l,r,mid+1,R);
		else res=qry(lc[k],l,mid,L,mid)+qry(rc[k],mid+1,r,mid+1,R);
		return res+1ll*lzy[k]*(r-l+1);
	}
	void era(int t){
		tim.back().se=t-1;rt.pb(0);int nul=0;
		ins(rt.back(),SZ(rt)>1?rt[SZ(rt)-2]:nul,seg.back().fi,seg.back().se,t-tim.back().fi,1,n);
	}
	void extend(int r, int i){
		era(i);seg.pb(mp(seg.back().fi,r));tim.pb(mp(i,inf));
	}
	void addseg(int l, int r, int t){
		if(SZ(seg)&&tim.back().se==inf){
			era(t);seg.pb(mp(min(seg.back().fi,l),max(seg.back().se,r)));tim.pb(mp(t,inf));
		}else ins(l,r,t);
	}
	int inter(int a, int b, int c, int d){return max(min(b,d)-max(a,c)+1,0);}
	ll qry(int l, int r){
	//	rep(i,0,SZ(tim)-1)printf("%d %d %d %d\n",seg[i].fi,seg[i].se,tim[i].fi,tim[i].se);
		if(tim.empty())return 0;
		int lo=0,hi=SZ(tim)-1;
		while(lo<hi){
			int mid=(lo+hi)>>1;
			if(tim[mid].se<=r)lo=mid+1;else hi=mid;
		}
	//	if(SZ(rt))printf("qaq %lld\n",(1?qry(rt[0],l,r,1,n):0));
	//	printf("qaq %lld\n",(lo?qry(rt[lo-1],l,r,1,n):0));
		return 1ll*inter(l,r,seg[lo].fi,seg[lo].se)*inter(0,r,tim[lo].fi,tim[lo].se)+(lo?qry(rt[lo-1],l,r,1,n):0);
	}
}yzr[N];
int val[N<<2];
void build(int k, int l, int r){
	if(l==r){val[k]=l?inf:0;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	val[k]=min(val[k<<1],val[k<<1|1]);
}
void mdy(int k, int p, int x, int l, int r){
	if(l==r){val[k]=x;return;}
	int mid=(l+r)>>1;
	if(p<=mid)mdy(k<<1,p,x,l,mid);else mdy(k<<1|1,p,x,mid+1,r);
	val[k]=min(val[k<<1],val[k<<1|1]);
}
int qrymn(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return val[k];
	int mid=(L+R)>>1;
	if(r<=mid)return qrymn(k<<1,l,r,L,mid);
	if(l>mid)return qrymn(k<<1|1,l,r,mid+1,R);
	return min(qrymn(k<<1,l,mid,L,mid),qrymn(k<<1|1,mid+1,r,mid+1,R));
}
int qry(int k, int p, int v, int L, int R){//p..n, 1st <v
	if(val[k]>=v)return n+1;
	if(L==R)return L;
	int mid=(L+R)>>1;
	if(p>mid)return qry(k<<1|1,p,v,mid+1,R);
	int x=qry(k<<1,p,v,L,mid);if(x<=n)return x;
	return qry(k<<1|1,p,v,mid+1,R);
}
int main() {
	read(n);ll lans=0;
	rep(i,0,n)p0.insert(i);build(1,0,n);
	rep(i,1,n){
		int l,r,k;read(a[i]);read(l);read(r);read(k);
		a[i]=(a[i]+lans)%(n+1);l=(l+lans)%i+1;r=(r+lans)%i+1;
		if(l>r)swap(l,r);k=(k+lans)%(n+1);
		if(!pos[a[i]])p0.erase(a[i]);mdy(1,pos[a[i]],pos[a[i]]?inf:*(p0.begin()),0,n);
		pos[a[i]]=i;mdy(1,i,a[i],0,n);bool flag=0;
	//	printf("ins %d\n",a[i]);
		if(SZ(yzr[a[i]].tim)&&yzr[a[i]].tim.back().se==inf){
			Pii ss=yzr[a[i]].seg.back();int v=qrymn(1,0,ss.fi-1,0,n);yzr[a[i]].era(i);//WA
		//	printf("%d [%d,%d]\n",i,ss.fi,ss.se);
			for(int l=ss.fi;l<=ss.se;){
				int p=min(qry(1,l,v,0,n),ss.se);
				yzr[v].addseg(l,p,i);
				v=a[p];l=p+1;
			}
		}
		if(!flag)yzr[!a[i]].addseg(i,i,i);
		printf("%lld\n",lans=yzr[k].qry(l,r));
	}
	return 0;
}