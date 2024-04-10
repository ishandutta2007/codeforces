#include<cstdio>
#include<iostream>
using namespace std;
const int o=4e5+10;
int n,m,q,L[o],R[o];long long ans,a[o],b[o],s[o],sv[o],co[o],mx[o],flg[o];
inline void update(int id){
	s[id]=s[id<<1]+s[(id<<1)|1];sv[id]=sv[id<<1]+sv[(id<<1)|1];
	co[id]=co[id<<1]+co[(id<<1)|1];mx[id]=max(mx[id<<1],mx[(id<<1)|1]);
}
void build(int id,int l,int r){
	L[id]=l;R[id]=r;
	if(l==r){s[id]=(sv[id]=mx[id]=b[l+1]-b[l])*(co[id]=m-l);return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	update(id);
}
inline void ad(int id,long long val){flg[id]+=val;mx[id]+=val;s[id]+=val*co[id];sv[id]+=val*(R[id]-L[id]+1);}
inline void pushdown(int id){if(flg[id]) ad(id<<1,flg[id]),ad((id<<1)|1,flg[id]),flg[id]=0;}
void modify(int id,int ql,int qr,long long val,int l=1,int r=m-1){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	update(id);
}
int bs(int id,long long val,int l=1,int r=m-1){
	if(l==r) return val<mx[id]?l-1:l;
	pushdown(id);
	int md=l+r>>1;
	if(val>=mx[id<<1]) return bs((id<<1)|1,val,md+1,r);
	return bs(id<<1,val,l,md);
}
long long query(int id,int ql,int qr,int l=1,int r=m-1){
	if(ql<=l&&r<=qr) return sv[id];
	pushdown(id);
	int md=l+r>>1;
	return (ql<=md?query(id<<1,ql,qr,l,md):0)+(md<qr?query((id<<1)|1,ql,qr,md+1,r):0);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i) scanf("%lld",&b[i]);
	build(1,1,m-1);
	for(int typ,k,d;q--;printf("%lld\n",ans)){
		scanf("%d%d%d",&typ,&k,&d);
		if(typ==1) for(int i=n;i>n-k;--i) a[i]+=(i-n+k)*d;
		else{
			if(k==m) --k,b[1]+=d;
			modify(1,m-k,m-1,d);
		}
		ans=s[1]+(a[1]+b[1])*(n+m-1);
		for(int i=2,j;i<=n;++i){
			if(j=bs(1,a[i]-a[i-1])) ans+=query(1,1,j);
			ans+=(a[i]-a[i-1])*(n-i+m-j);
		}
	}
	return 0;
}