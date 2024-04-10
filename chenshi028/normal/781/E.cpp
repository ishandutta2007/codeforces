#include<cstdio>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
const int o=1e5+10,inf=2e9+10,MOD=1e9+7;
int h,w,n,mn[o*4],ans;pair<pair<int,int>,pair<int,int> > d[o];priority_queue<pair<int,int> > q[o];
#define fi first
#define se second
void build(int id,int l,int r){
	mn[id]=h+1;
	if(l==r){q[l].push(make_pair(-h-1,1));return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void update(int id){mn[id]=(mn[id<<1]<mn[(id<<1)|1])?mn[id<<1]:mn[(id<<1)|1];}
void modify(int id,int l,int r,int pos,int num,int ht){
	if(l==r){q[l].push(make_pair(-ht,num));if(mn[id]>ht) mn[id]=ht;return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,l,md,pos,num,ht);
	else modify((id<<1)|1,md+1,r,pos,num,ht);
	update(id);
}
int query(int id,int ql,int qr,int l,int r,int val){
	if(mn[id]>val) return 0;
	if(l==r){
		int res=0;
		for(;!q[l].empty()&&-q[l].top().fi<=val;q[l].pop()) res=(res+q[l].top().se)%MOD;
		mn[id]=(q[l].empty()?inf:-q[l].top().fi);
		return res;
	}
	int md=l+r>>1,res=0;
	if(ql<=md) res=query(id<<1,ql,qr,l,md,val);
	if(md<qr) res=(res+query((id<<1)|1,ql,qr,md+1,r,val))%MOD;
	update(id);
	return res;
}
int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;++i) scanf("%d%d%d%d",&d[i].fi.fi,&d[i].se.fi,&d[i].se.se,&d[i].fi.se);
	sort(d+1,d+n+1);
	build(1,1,ans=w);
	for(int i=n,j;i;--i,ans=(ans+j)%MOD){
		j=query(1,d[i].se.fi,d[i].se.se,1,w,d[i].fi.fi+d[i].fi.se);
		if(d[i].se.fi==1) modify(1,1,w,d[i].se.se+1,2*j%MOD,d[i].fi.fi);
		else if(d[i].se.se==w) modify(1,1,w,d[i].se.fi-1,2*j%MOD,d[i].fi.fi);
		else modify(1,1,w,d[i].se.fi-1,j,d[i].fi.fi),modify(1,1,w,d[i].se.se+1,j,d[i].fi.fi);
	}
	printf("%d",ans);
	return 0;
}