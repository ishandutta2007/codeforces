#include<cstdio>
#include<iostream>
using namespace std;
const int o=8e5+10;
int n,q,mx[o],se[o],cnt[o],flg[o];
	namespace SGT{
int flg[o];long long s[o];
void build(int id,int l,int r){
	s[id]=r-l+1;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void ad(int id,int len,int val){s[id]+=val*1ll*len;flg[id]+=val;}
inline void pushdown(int id,int len){ad(id<<1,len+1>>1,flg[id]);ad((id<<1)|1,len>>1,flg[id]);flg[id]=0;}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){ad(id,r-l+1,val);return;}
	pushdown(id,r-l+1);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	s[id]=s[id<<1]+s[(id<<1)|1];
}
long long query(int id,int ql,int qr,int l=1,int r=n){
	if(ql<=l&&r<=qr) return s[id];
	pushdown(id,r-l+1);
	int md=l+r>>1;
	return (ql<=md?query(id<<1,ql,qr,l,md):0)+(md<qr?query((id<<1)|1,ql,qr,md+1,r):0);
}
	}
void build(int id,int l,int r){
	mx[id]=r;se[id]=r-1;cnt[id]=1;flg[id]=o;
	if(l==r){se[id]=-1;return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void ad(int id,int val){mx[id]=min(mx[id],val);flg[id]=min(flg[id],val);}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=o;}
inline void update(int id){
	mx[id]=max(mx[id<<1],mx[(id<<1)|1]);se[id]=max(se[id<<1],se[(id<<1)|1]);cnt[id]=0;
	if(mx[id<<1]<mx[id]) se[id]=max(se[id],mx[id<<1]);
	else cnt[id]+=cnt[id<<1];
	if(mx[(id<<1)|1]<mx[id]) se[id]=max(se[id],mx[(id<<1)|1]);
	else cnt[id]+=cnt[(id<<1)|1];
}
void assign(int id,int pos,int val,int l=1,int r=n){
	if(l==r){SGT::modify(1,pos,mx[id],-1);SGT::modify(1,pos,mx[id]=val,1);return;}
	pushdown(id);
	int md=l+r>>1;
	if(pos<=md) assign(id<<1,pos,val,l,md);
	else assign((id<<1)|1,pos,val,md+1,r);
	update(id);
}
void modify(int id,int ql,int qr,int val,int l=1,int r=n){
	if(ql<=l&&r<=qr){
		if(val>=mx[id]) return;
		if(val>se[id]){SGT::modify(1,val+1,mx[id],-cnt[id]);ad(id,val);return;}
	}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	update(id);
}
int main(){
	scanf("%d%d",&n,&q);
	SGT::build(1,1,n);build(1,1,n);
	for(int p,x,y;q--;){
		scanf("%d%d%d",&p,&x,&y);
		if(p==1){
			assign(1,x,y);
			if(x>1) modify(1,1,x-1,x-1);
		}
		else printf("%lld\n",SGT::query(1,x,y));
	}
	return 0;
}