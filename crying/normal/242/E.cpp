#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define next Cry_FortheMoon
typedef long long ll;
using namespace std;
const int MAXN=1e5+10;
struct SegmentTree{
	int sum[MAXN<<2],tag[MAXN<<2],l[MAXN<<2],r[MAXN<<2];
	void build(int x,int llim,int rlim,int a[]){
		l[x]=llim,r[x]=rlim;
		if(l[x]==r[x]){sum[x]=a[l[x]];return;}
		int mid=l[x]+r[x]>>1;
		build(lc(x),l[x],mid,a);build(rc(x),mid+1,r[x],a); 
		push_up(x);
	}
	void push_up(int x){
		sum[x]=sum[lc(x)]+sum[rc(x)];
	}
	void push_down(int x){
		if(!tag[x])return;
		sum[lc(x)]=r[lc(x)]-l[lc(x)]+1-sum[lc(x)];
		sum[rc(x)]=r[rc(x)]-l[rc(x)]+1-sum[rc(x)];
		tag[lc(x)]^=1,tag[rc(x)]^=1,tag[x]=0;
	}
	void update(int x,int ql,int qr){
		if(ql<=l[x] && qr>=r[x]){
			sum[x]=r[x]-l[x]+1-sum[x];
			tag[x]^=1;
			return;
		} 
		push_down(x);
		int mid=l[x]+r[x]>>1;
		if(ql<=mid)update(lc(x),ql,qr);
		if(qr>mid)update(rc(x),ql,qr);
		push_up(x); 
	}
	int query(int x,int ql,int qr){
		if(ql<=l[x] && qr>=r[x]){
			return sum[x];
		}
		push_down(x);
		int mid=l[x]+r[x]>>1,ret=0;
		if(ql<=mid)ret+=query(lc(x),ql,qr);
		if(qr>mid)ret+=query(rc(x),ql,qr);
		push_up(x);return ret;
	}
}tree[22];
int n,a[22][MAXN],tmp,m,op,l,r,v;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&tmp);
		rep(j,0,21){a[j][i]=(tmp>>j)&1;}
	}
	rep(j,0,21)tree[j].build(1,1,n,a[j]);
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&l,&r);
			ll sum=0;
			rep(j,0,21){
				sum+=(1LL<<j)*tree[j].query(1,l,r);
			}
			printf("%lld\n",sum);
		}else{
			scanf("%d%d%d",&l,&r,&v);
			rep(j,0,21){
				if((v>>j)&1){
					tree[j].update(1,l,r);
				}
			}
		}
	}
	return 0;
}