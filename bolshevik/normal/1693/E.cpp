#include<cstdio>
using namespace std;
const int o=8e5;
int n,a[o],b[o],cnt[o][2];long long ans;
struct node{int stp[3],lst[3];}z[4],v[o];
node merge(node L,node R){
	node res;
	for(int i=0;i<3;++i) res.stp[i]=L.stp[R.lst[i]]+R.stp[i],res.lst[i]=L.lst[R.lst[i]];
	return res;
}
void build(int id,int l,int r){
	if(l==r){v[id]=z[0];return;}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	v[id]=merge(v[id<<1],v[(id<<1)|1]);
}
void modify(int id,int pos,int val,int l=0,int r=n){
	if(l==r){v[id]=z[b[l]+=val];return;}
	int md=l+r>>1;
	if(pos<=md) modify(id<<1,pos,val,l,md);
	else modify((id<<1)|1,pos,val,md+1,r);
	v[id]=merge(v[id<<1],v[(id<<1)|1]);
}
node query(int id,int ql,int qr,int l=0,int r=n){
	if(ql<=l&&r<=qr) return v[id];
	int md=l+r>>1;
	if(qr<=md) return query(id<<1,ql,qr,l,md);
	if(md<ql) return query((id<<1)|1,ql,qr,md+1,r);
	return merge(query(id<<1,ql,qr,l,md),query((id<<1)|1,ql,qr,md+1,r));
}
int main(){
	scanf("%d",&n);cnt[0][0]=cnt[0][1]=1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),++cnt[a[i]][1];
	z[0].lst[1]=z[1].stp[2]=z[1].lst[0]=z[1].lst[1]=z[2].stp[1]=z[3].stp[0]=z[3].stp[1]=z[3].stp[2]=1;
	z[0].lst[2]=z[2].lst[0]=z[2].lst[2]=2;
	build(1,0,n);modify(1,0,3);
	for(int i=1;i<=n;++i) if(cnt[i][1]) modify(1,i,2);
	for(int i=1;i<=n;++i){
		if(!--cnt[a[i]][1]) modify(1,a[i],-2);
		if(a[i]) ans+=query(1,0,a[i]-1).stp[0];
		if(!cnt[a[i]][0]++) modify(1,a[i],1);
	}
	printf("%lld",ans);
	return 0;
}