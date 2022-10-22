// Problem: CF1290E Cartesian Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1290E
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
typedef long long ll;
const int N=1.5e5+10;
const int inf=2e9;
int n,a[N];pair<int,int>p[N];
ll ans[N];
ll sum[N<<2];//
int mx1[N<<2];//
int smx[N<<2];//
int mx2[N<<2];//
int cnt[N<<2];//
int tag[N<<2];//
int lazy[N<<2];//
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void pushup(int x){
	sum[x]=sum[lc]+sum[rc];
	cnt[x]=cnt[lc]+cnt[rc];
	if(mx1[lc]==mx1[rc]){
		mx1[x]=mx1[lc];
		smx[x]=smx[lc]+smx[rc];
		mx2[x]=max(mx2[lc],mx2[rc]);
	}else{
		mx1[x]=max(mx1[lc],mx1[rc]);
		smx[x]=mx1[lc]>mx1[rc]?smx[lc]:smx[rc];
		mx2[x]=max(min(mx1[lc],mx1[rc]),max(mx2[lc],mx2[rc]));
	}
}
void upd(int x,int k1,int k2){
	//k1
	//k2
	sum[x]+=1ll*k1*smx[x];
	sum[x]+=1ll*k2*(cnt[x]-smx[x]);
	if(mx1[x]!=-inf)mx1[x]+=k1;tag[x]+=k1;
	if(mx2[x]!=-inf)mx2[x]+=k2;lazy[x]+=k2;
}
void pushdown(int x){
	int _=max(mx1[lc],mx1[rc]);
	if(mx1[lc]==_)upd(lc,tag[x],lazy[x]);
	else upd(lc,lazy[x],lazy[x]);
	if(mx1[rc]==_)upd(rc,tag[x],lazy[x]);
	else upd(rc,lazy[x],lazy[x]);
	lazy[x]=tag[x]=0;
}
void build(int x,int l,int r){
	if(l==r){
		mx1[x]=-inf;smx[x]=0;
		mx2[x]=-inf;
		cnt[x]=0;sum[x]=0;
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(x);
}
void Plus(int x,int l,int r,int ql,int qr,int val){
	if(r<ql||qr<l)return;
	if(ql<=l&&r<=qr){
		upd(x,val,val);
		return;
	}
	pushdown(x);
	Plus(lc,l,mid,ql,qr,val);
	Plus(rc,mid+1,r,ql,qr,val);
	pushup(x);
}
void Min(int x,int l,int r,int ql,int qr,int A){
	if(r<ql||qr<l||mx1[x]<=A)return;
	if(ql<=l&&r<=qr&&mx2[x]<A){
		upd(x,A-mx1[x],0);
		return;
	}
	pushdown(x);
	Min(lc,l,mid,ql,qr,A);
	Min(rc,mid+1,r,ql,qr,A);
	pushup(x);
}
void Ins(int x,int l,int r,int pos,int val){
	if(l==r){
		sum[x]=mx1[x]=val;
		smx[x]=cnt[x]=1;
		cnt[x]=1;return;
	}
	pushdown(x);
	if(pos<=mid)Ins(lc,l,mid,pos,val);
	else Ins(rc,mid+1,r,pos,val);
	pushup(x);
}
ll Sum(int x,int l,int r,int ql,int qr){
	if(r<ql||qr<l)return 0;
	if(ql<=l&&r<=qr)return sum[x];
	pushdown(x);
	return Sum(lc,l,mid,ql,qr)+Sum(rc,mid+1,r,ql,qr);
}
int Cnt(int x,int l,int r,int ql,int qr){
	if(r<ql||qr<l)return 0;
	if(ql<=l&&r<=qr)return cnt[x];
	pushdown(x);
	return Cnt(lc,l,mid,ql,qr)+Cnt(rc,mid+1,r,ql,qr);
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]),p[i]={a[i],i};
	sort(p+1,p+1+n);
	for(int SS=1;SS<=2;SS++){
		build(1,1,n);
		for(int i=1;i<=n;i++){
			int pos=p[i].second;
			int pre=Cnt(1,1,n,1,pos);
			if(pos!=1)
				Min(1,1,n,1,pos-1,pre);
			if(pos!=n)
				Plus(1,1,n,pos+1,n,1);
			Ins(1,1,n,pos,i);
			ans[i]+=sum[1];
		}
		for(int i=1;i<=n;i++)p[i].second=n-p[i].second+1;
	}
	for(int i=1;i<=n;i++)
		write(ans[i]-1ll*i*i),putchar('\n');
}