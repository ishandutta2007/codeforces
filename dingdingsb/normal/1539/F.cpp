// Problem: F. Strange Array
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+100;
const int inf=0x3f3f3f3f;
struct SGT{
	int mn[N<<2],mx[N<<2],tag[N<<2];
	#define lc (x<<1)
	#define rc (x<<1|1)
	#define mid ((l+r)>>1)
	void pushup(int x){
		mn[x]=min(mn[lc],mn[rc]);
		mx[x]=max(mx[lc],mx[rc]);
	}
	void pushdown(int x){
		if(tag[x]){
			mn[lc]+=tag[x];mx[lc]+=tag[x];
			mn[rc]+=tag[x];mx[rc]+=tag[x];
			tag[lc]+=tag[x];tag[rc]+=tag[x];
			tag[x]=0;
		}
	}
	void build(int x,int l,int r){
		tag[x]=0;
		if(l==r)return void(mn[x]=mx[x]=l);
		build(lc,l,mid);
		build(rc,mid+1,r);
		pushup(x);
	}
	void upd(int x,int l,int r,int ql,int qr,int val){
		if(ql<=l&&r<=qr){
			tag[x]+=val;
			mn[x]+=val;
			mx[x]+=val;
			return;
		}
		if(qr<l||r<ql)return;
		pushdown(x);
		upd(lc,l,mid,ql,qr,val);
		upd(rc,mid+1,r,ql,qr,val);
		pushup(x);
	}
	int qmx(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mx[x];
		if(qr<l||r<ql)return -inf;
		pushdown(x);
		return max(qmx(lc,l,mid,ql,qr),qmx(rc,mid+1,r,ql,qr));
	}
	int qmn(int x,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[x];
		if(qr<l||r<ql)return inf;
		pushdown(x);
		return min(qmn(lc,l,mid,ql,qr),qmn(rc,mid+1,r,ql,qr));
	}
}T;
int n,a[N],id[N];
int ans[N];
vector<int>vec[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),id[i]=i,vec[a[i]].push_back(i);
	sort(id+1,id+1+n,[&](int x,int y)->bool{return a[x]<a[y];});
	T.build(1,0,n);
	for(int i=1;i<=n;i++){
		int x=id[i];
		if(a[id[i-1]]!=a[id[i]]&&i!=1)
			for(auto x:vec[a[id[i-1]]])
				T.upd(1,0,n,x,n,-2);
		T.upd(1,0,n,x,n,-2);
		int val=T.qmx(1,0,n,x,n)-T.qmn(1,0,n,0,x-1);
		//printf("%d\n",val);
		if(val>=0)
		ans[x]=max(ans[x],val/2+1);
		T.upd(1,0,n,x,n,2);
	}
	T.build(1,0,n);
	for(int i=1;i<=n;i++){
		int x=id[i];
		if(a[id[i-1]]!=a[id[i]])
			for(auto x:vec[a[id[i]]])
				T.upd(1,0,n,x,n,-2);
		T.upd(1,0,n,x,n,2);
		int val=T.qmn(1,0,n,x,n)-T.qmx(1,0,n,0,x-1);
		//printf("%d\n",val);
		if(val<=0)
		ans[x]=max(ans[x],(-val+1)/2);
		T.upd(1,0,n,x,n,-2);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}