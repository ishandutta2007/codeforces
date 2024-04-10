#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;
const int MAXN=1e5+10;
ll n,m,q;
ll a[MAXN],b[MAXN],type,k,d;
ll da[MAXN],db[MAXN];
ll s;
void Read(ll& num){
	char ch;
	while((ch=getchar()) && !isdigit(ch));
	num=ch-'0';
	while((ch=getchar()) && isdigit(ch))num=num*10+ch-'0';
}
struct SegmentTree{
	ll sum[MAXN<<2],tag[MAXN<<2],rv[MAXN<<2];
	void pushup(int x){sum[x]=sum[lc(x)]+sum[rc(x)];rv[x]=rv[rc(x)];}
	void pushdown(int x,int l,int r){
		if(!tag[x])return;
		int mid=(l+r)>>1;sum[lc(x)]+=tag[x]*(mid-l+1);sum[rc(x)]+=tag[x]*(r-mid);
		rv[lc(x)]+=tag[x];rv[rc(x)]+=tag[x];
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];tag[x]=0;
	} 
	void upd(int x,int l,int r,int ql,int qr,ll val){
		if(ql<=l && qr>=r){
			sum[x]+=val*(r-l+1);tag[x]+=val;rv[x]+=val; 
			return;
		}
		pushdown(x,l,r);int mid=(l+r)>>1;
		if(ql<=mid)upd(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	void build(int x,int l,int r){
		if(l==r){
			sum[x]=rv[x]=db[l];
			return;
		}
		int mid=(l+r)>>1;build(lc(x),l,mid);build(rc(x),mid+1,r);pushup(x);
	}
	ll qry(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return sum[x];
		pushdown(x,l,r);
		int mid=(l+r)>>1;ll ret=0;
		if(ql<=mid)ret+=qry(lc(x),l,mid,ql,qr);
		if(qr>mid)ret+=qry(rc(x),mid+1,r,ql,qr);
		pushup(x);return ret;
	}
	int search(int x,int l,int r,ll val){
		if(l==r)return l;
		int mid=(l+r)>>1;
		pushdown(x,l,r);
		int ret=0;	
		if(rv[lc(x)]>=val)ret=search(lc(x),l,mid,val);
		else ret=search(rc(x),mid+1,r,val);
		pushup(x);return ret; 
	}
}t; 
ll S(ll n){return n*(n+1)/2;}
int main(){
	Read(n);Read(m);Read(q);
	
	rep(i,1,n)Read(a[i]);
	rep(i,1,m)Read(b[i]);
	rep(i,2,n)da[i]=a[i]-a[i-1];
	rep(i,2,m)db[i]=b[i]-b[i-1];
	rep(i,2,m)s+=db[i]*(m-i+1);
	t.build(1,2,m);
	rep(i,1,q){
		Read(type);Read(k);Read(d);
		if(type==1){
			if(k==n){a[1]+=d;k--;}
			rep(i,n-k+1,n)da[i]+=d;
		}else{
			if(k==m){b[1]+=d;k--;}
			s+=d*S(k);
			t.upd(1,2,m,m-k+1,m,d);
		}
		ll ans=s+(n+m-1)*(a[1]+b[1]);
		ll sm=t.qry(1,2,m,2,m);
		rep(i,2,n){
			//find ai's positionS
			if(t.qry(1,2,m,m,m)<da[i]){ans+=sm;continue;}
			int pos=t.search(1,2,m,da[i]);
			if(pos!=2)ans+=t.qry(1,2,m,2,pos-1);
			ans+=da[i]*(m-pos+1);	
		}
		rep(i,2,n)ans+=da[i]*(n-i+1);
		printf("%lld\n",ans);
	}

	return 0;
}