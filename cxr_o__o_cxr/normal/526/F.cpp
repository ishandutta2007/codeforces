//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,fl=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')fl=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return fl==1?x:-x;
}
#define ll long long
const int N=3e5+4;
namespace seg{
	#define lc (p<<1)
	#define rc (p<<1|1)
	int mn[N<<2],t[N<<2],lz[N<<2];
	inline void pushup(int p){
		mn[p]=min(mn[lc],mn[rc]);
		t[p]=(mn[p]==mn[lc]?t[lc]:0)+(mn[p]==mn[rc]?t[rc]:0);
	}
	inline void pushdown(int p){
		if(!lz[p])return;
		lz[lc]+=lz[p];lz[rc]+=lz[p];
		mn[lc]+=lz[p];mn[rc]+=lz[p];
		lz[p]=0;
	}
	void build(int p,int l,int r){
		t[p]=r-l+1;
		if(l==r)return;
		int mid=l+r>>1;
		build(lc,l,mid);build(rc,mid+1,r);
	}
	void modify(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr){
			lz[p]+=v;mn[p]+=v;
			return;
		}
		int mid=l+r>>1;
		pushdown(p);
		if(ql<=mid)modify(lc,l,mid,ql,qr,v);
		if(mid<qr)modify(rc,mid+1,r,ql,qr,v);
		pushup(p);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return mn[p]==0?t[p]:0;
		int mid=l+r>>1;
		pushdown(p);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
	}
}
int n,top1,top2,a[N],st1[N],st2[N];
ll ans;
int main(){
	n=read();
	for(int i=1,x;i<=n;i++){x=read();a[x]=read();}
	seg::build(1,1,n);
	for(int i=1;i<=n;i++){
		while(top1&&a[st1[top1]]<=a[i]){
			seg::modify(1,1,n,st1[top1-1]+1,st1[top1],-a[st1[top1]]);
			top1--;
		}
		while(top2&&a[st2[top2]]>=a[i]){
			seg::modify(1,1,n,st2[top2-1]+1,st2[top2],a[st2[top2]]);
			top2--;
		}
		seg::modify(1,1,n,st1[top1]+1,i,a[i]);
		seg::modify(1,1,n,st2[top2]+1,i,-a[i]);
		if(i-1)seg::modify(1,1,n,1,i-1,-1);
		st1[++top1]=i;st2[++top2]=i;
		ans+=seg::query(1,1,n,1,i);
	}
	cout<<ans;
	return (0-0);
}