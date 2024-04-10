#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
int n,a[MAXN],pos[MAXN],rk[MAXN];
struct BIT{
	int t[MAXN];
	void add(int x){for(;x<=n;x+=lowbit(x))t[x]++;}
	int qry(int x,int s=0){for(;x;x-=lowbit(x))s+=t[x];return s;}
}bit;
struct Seg{
	ll sum[MAXN<<2],atag[MAXN<<2];
	int cnt[MAXN<<2],max1[MAXN<<2],max2[MAXN<<2],tag[MAXN<<2],len[MAXN<<2];
	void pushup(int x){
		sum[x]=sum[lc(x)]+sum[rc(x)];
		len[x]=len[lc(x)]+len[rc(x)];
		max1[x]=max(max1[lc(x)],max1[rc(x)]);
		if(max1[lc(x)]>max1[rc(x)])max2[x]=max(max2[lc(x)],max1[rc(x)]),cnt[x]=cnt[lc(x)];
		else if(max1[lc(x)]<max1[rc(x)])max2[x]=max(max1[lc(x)],max2[rc(x)]),cnt[x]=cnt[rc(x)];
		else max2[x]=max(max2[lc(x)],max2[rc(x)]),cnt[x]=cnt[lc(x)]+cnt[rc(x)];
	}
	//first add,then min
	void Add(int x,ll val){sum[x]+=len[x]*val;atag[x]+=val;max1[x]+=val;max2[x]+=val;tag[x]+=val;}
	void Min(int x,ll val){if(val<max1[x])sum[x]-=cnt[x]*(max1[x]-val),tag[x]=max1[x]=val;}
	void pushdown(int x){
		if(atag[x])Add(lc(x),atag[x]),Add(rc(x),atag[x]),atag[x]=0;
		if(tag[x]!=INF)Min(lc(x),tag[x]),Min(rc(x),tag[x]),tag[x]=INF;
	}
	void upd_min(int x,int l,int r,int ql,int qr,ll val){
		if(!len[x])return;
		if(ql>qr)return;
		if(max1[x]<=val)return;
		if(ql<=l && qr>=r && val>=max2[x])return Min(x,val);
		int mid=(l+r)>>1;pushdown(x);
		if(ql<=mid)upd_min(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd_min(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	void upd_add(int x,int l,int r,int ql,int qr,ll val){
		if(!len[x])return;
		if(ql>qr)return;
		if(ql<=l && qr>=r)return Add(x,val);
		int mid=(l+r)>>1;pushdown(x);
		if(ql<=mid)upd_add(lc(x),l,mid,ql,qr,val);
		if(qr>mid)upd_add(rc(x),mid+1,r,ql,qr,val);
		pushup(x);
	}
	void upd_one(int x,int l,int r,int pos,ll val){
		if(l==r)return (void)(sum[x]=max1[x]=val,max2[x]=-INF,cnt[x]=len[x]=1);
		int mid=(l+r)>>1;pushdown(x);
		(pos<=mid)?(upd_one(lc(x),l,mid,pos,val)):(upd_one(rc(x),mid+1,r,pos,val));
		pushup(x);
	}
	void build(int x,int l,int r){
		max1[x]=max2[x]=-INF;tag[x]=INF;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		pushup(x);
	}
}L,R;
int main(){
	cin>>n;
	rep(i,1,n)cin>>a[i],pos[a[i]]=i,rk[i]=bit.qry(a[i]),bit.add(a[i]);
	L.build(1,1,n);R.build(1,1,n);
	rep(k,1,n){
		int p=pos[k],pp=rk[p]+1;
		L.upd_one(1,1,n,p,0);R.upd_one(1,1,n,p,k+1);
		L.upd_add(1,1,n,p+1,n,-1);R.upd_add(1,1,n,p+1,n,1);
		L.upd_min(1,1,n,p+1,n,-pp);R.upd_min(1,1,n,1,p-1,pp);
		cout<<L.sum[1]+R.sum[1]-k<<endl;
	}
	return 0;
}