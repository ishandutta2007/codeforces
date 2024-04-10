#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
struct SEG{
	int t[N<<2];
	void build(int p,int l,int r){
		t[p]=0;
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void up(int p){ t[p]=max(t[p+p],t[p+p+1]); }
	int query(int p,int l,int r,int x,int y){
		if(y<l||r<x) return 0;
		if(x<=l&&r<=y) return t[p];
		int m=l+r>>1;
		return max(query(p+p,l,m,x,y),query(p+p+1,m+1,r,x,y));
	}
	void change(int p,int l,int r,int x,int k){
		if(x<l||r<x) return;
		if(l==r){
			t[p]=max(t[p],k);
			return;
		}
		int m=l+r>>1;
		change(p+p,l,m,x,k);
		change(p+p+1,m+1,r,x,k);
		up(p);
	}
}seg1,seg2;
struct BIT{
	int c[N],a[N];
	void init(int n){ for(int i=1;i<=n;++i) a[i]=c[i]=0; }
	void add(int x,int k){
		a[x]=max(a[x],k);
		for(;x<N;x+=x&-x)
			c[x]=max(c[x],k);
	}
	int query(int x){
		int ret=0;
		for(;x;x-=x&-x)
			ret=max(ret,c[x]);
		return ret; 
	}
}bit1,bit2;
struct DSF{
	int fa[N];
	void init(int n){ 
		for(int i=0;i<=n;++i) fa[i]=i; 
	}
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		x=fs(x); y=fs(y);
		assert(x!=y);
		fa[y]=x;
	}
}dsf_max,dsf_min;
int main(){
	int n,q; scanf("%d%d",&n,&q);
	seg1.build(1,1,n);
	seg2.build(1,1,n);
	dsf_max.init(n+1); dsf_min.init(n+1);
	while(q--){
		int op; scanf("%d",&op);
		if(op==0){
			int l,r,x; scanf("%d%d%d",&l,&r,&x);
			if(x==1){
				l=dsf_max.fs(l);
				r=dsf_min.fs(r);
				seg1.change(1,1,n,l,n-r+1);
				seg2.change(1,1,n,r,l);
			}else{
				l=dsf_min.fs(l-1)+1;
				r=dsf_max.fs(r+1)-1;
//				printf("<%d %d>",l,r);
				int mir=n-seg1.query(1,1,n,l,r)+1;
				int mxl=seg2.query(1,1,n,l,r);
				if(l-1>0) seg1.change(1,1,n,l-1,n-mir+1);
				if(r+1<=n) seg2.change(1,1,n,r+1,mxl);
				for(int x=dsf_max.fs(l);x<=r;x=dsf_max.fs(x+1))
					dsf_max.merge(x+1,x);
				for(int x=dsf_min.fs(r);x>=l;x=dsf_min.fs(x-1))
					dsf_min.merge(x-1,x);
			}
		}else{
			int x,ans=-1; scanf("%d",&x);
			if(dsf_max.fs(x)!=x) ans=0;
			if(1){
				int mir=dsf_min.fs(n-seg1.query(1,1,n,x,x)+1);
				if(mir==x) ans=1;
			}
			if(1){
				int mxl=dsf_max.fs(seg2.query(1,1,n,x,x));
				if(mxl==x) ans=1;
			}
			if(ans==0) puts("NO");
			else if(ans==1) puts("YES");
			else puts("N/A");
		}
//		for(int x=1;x<=n;++x) printf("(%d)",n-bit1.a[x]+1); puts("");
//		for(int x=1;x<=n;++x) printf("(%d)",bit2.a[n-x+1]); puts("");
//		puts("---");
	}
	return 0;
}