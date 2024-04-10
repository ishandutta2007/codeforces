#include<bits/stdc++.h>
#define LL long long
#define L x<<1
#define R x<<1|1
using namespace std;
const int N=2e5+50;
int n,q,a[N],stx[N],tpx,stn[N],tpn;LL ans[N];
struct node{int l,r,id;bool friend operator <(node a,node b){return a.r<b.r;}}Q[N];
int mn[N*4],cnt[N*4],laz[N*4],laz2[N*4];LL sum[N*4];
void mdf(int x,int d){mn[x]+=d;laz[x]+=d;}
void mdf2(int x,int d){sum[x]+=1ll*d*cnt[x];laz2[x]+=d;}
void down(int x){
	if(laz[x])mdf(L,laz[x]),mdf(R,laz[x]),laz[x]=0;
	if(laz2[x]){
		bool fl=mn[L]<=mn[R],fr=mn[R]<=mn[L];
		if(fl)mdf2(L,laz2[x]);if(fr)mdf2(R,laz2[x]);
		laz2[x]=0;
	}
}
void up(int x){
	mn[x]=min(mn[L],mn[R]);sum[x]=sum[L]+sum[R];
	cnt[x]=(mn[L]^mn[x]?0:cnt[L])+(mn[R]^mn[x]?0:cnt[R]);
}
void build(int x,int l,int r){
	if(l==r){mn[x]=l;cnt[x]=1;return;}
	int mid=(l+r)>>1;
	build(L,l,mid);build(R,mid+1,r);
	up(x);
}
void change(int x,int l,int r,int ql,int qr,int d,int t){
	if(l>qr||r<ql)return;
	if(l>=ql&&r<=qr){
		int fl=mn[x];mdf(x,d);
		if(fl&&!mn[x])mdf2(x,-t);
		if(!fl&&mn[x])mdf2(x,t);
		return;
	}
	int mid=(l+r)>>1;down(x);
	change(L,l,mid,ql,qr,d,t);
	change(R,mid+1,r,ql,qr,d,t);
	up(x);
}
LL query(int x,int l,int r,int ql,int qr,int t){
	if(l>qr||r<ql)return 0;
	if(l>=ql&&r<=qr)return 1ll*t*(mn[x]?0:cnt[x])+sum[x];
	int mid=(l+r)>>1;down(x);
	return query(L,l,mid,ql,qr,t)+query(R,mid+1,r,ql,qr,t);
}
int main(){
	scanf("%d",&n);build(1,1,n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;i++)scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id=i;
	sort(Q+1,Q+q+1);
	for(int i=1,j=0;i<=n;i++){
		while(tpx&&a[stx[tpx]]<a[i])change(1,1,n,stx[tpx-1]+1,stx[tpx],-a[stx[tpx]],i-1),tpx--;
		while(tpn&&a[stn[tpn]]>a[i])change(1,1,n,stn[tpn-1]+1,stn[tpn],a[stn[tpn]],i-1),tpn--;
		change(1,1,n,stx[tpx]+1,i,a[i],i-1);stx[++tpx]=i;
		change(1,1,n,stn[tpn]+1,i,-a[i],i-1);stn[++tpn]=i;
		change(1,1,n,1,n,-1,i-1);
		while(j<q&&Q[j+1].r<=i)j++,ans[Q[j].id]=query(1,1,n,Q[j].l,i,i);
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;   
}