#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
typedef double db;
using namespace std;
const int MAXN=3e5+10,LIM=3e5;
ll n,a[MAXN];
struct SegmentTree{
	ll tree[MAXN<<2],tag[MAXN<<2];
	void pushup(int x){tree[x]=tree[lc(x)]+tree[rc(x)];}
	void pushdown(int x,int l,int r){
		if(!tag[x])return;
		int mid=(l+r)>>1;
		tree[lc(x)]+=tag[x]*(mid-l+1);tree[rc(x)]+=tag[x]*(r-mid);
		tag[lc(x)]+=tag[x];tag[rc(x)]+=tag[x];
		tag[x]=0;
	} 
	void update(int x,int l,int r,int ql,int qr,ll val){
		if(ql>qr)return;
		if(ql<=l && qr>=r){
			tree[x]+=(val)*(r-l+1);
			tag[x]+=val;
			return;
		}
		pushdown(x,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid)update(lc(x),l,mid,ql,qr,val);
		if(qr>mid)update(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	void query(int x,int l,int r,int ql,int qr,ll& val){
		if(ql>qr)return;
		if(ql<=l && qr>=r){
			val+=tree[x];
			return;
		}
		pushdown(x,l,r);
		int mid=(l+r)>>1;
		if(ql<=mid)query(lc(x),l,mid,ql,qr,val);
		if(qr>mid)query(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
}p,bucket;
struct BIT{
	ll tree[MAXN];
	void update(ll x,ll val){
		if(x<1 || x>LIM)return;
		for(;x<=LIM;x+=lowbit(x))tree[x]+=val;
	}	
	void query(ll x,ll& val){
		if(x<1 || x>LIM)return;
		for(;x;x-=lowbit(x))val+=tree[x];
	}
	void query(ll L,ll R,ll& val){
		ll a=0,b=0;
		if(L>R)return;
		query(L-1,a);query(R,b);
		val=b-a;
	}
}t1,t2;
il void read(ll& num){
	char ch;
	while((ch=getchar()) && (ch<'0' || ch>'9'));
	num=ch-'0';
	while((ch=getchar()) && (ch>='0' && ch<='9'))num=num*10+ch-'0';
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	read(n);
	rep(i,1,n){
		read(a[i]);
	}	
	rep(i,1,n){
		//aj>ai
		//1.ai mod aj
		ll cnt=0,cnt2=0;
		t1.query(a[i]+1,LIM,cnt);
		p.update(1,1,n,i,n,cnt*a[i]);
		//2.aj mod ai
		cnt=0;
		t2.query(a[i]+1,LIM,cnt);
		rep(j,1,LIM){
			if(a[i]*j>LIM)break;
			ll L=a[i]*j,R=Min(LIM,a[i]*(j+1)-1);
			cnt2=0;
			t1.query(L,R,cnt2);
			cnt-=cnt2*a[i]*j;
		}
		p.update(1,1,n,i,n,cnt);
		//aj<ai
		//1.aj mod ai
		cnt=0;
		t2.query(1,a[i]-1,cnt);
		p.update(1,1,n,i,n,cnt);
		//2.ai mod aj
		cnt=cnt2=0;
		t1.query(1,a[i]-1,cnt);
		bucket.query(1,1,LIM,a[i],a[i],cnt2);
		p.update(1,1,n,i,n,cnt*a[i]-cnt2);
		//update
		t1.update(a[i],1);
		t2.update(a[i],a[i]);
		rep(j,1,LIM){
			if(a[i]*j>LIM)break;
			ll L=a[i]*j,R=a[i]*(j+1)-1;
			bucket.update(1,1,LIM,L,R,a[i]*j);
		}
	}
	rep(i,1,n){
		ll tmp=0;
		p.query(1,1,n,i,i,tmp);
		printf("%lld ",tmp);
	}
	
	return 0;
}