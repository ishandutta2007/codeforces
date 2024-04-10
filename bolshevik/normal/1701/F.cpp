#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int o=1e6,E=2e5;
int q,d;long long v[2][3][o],flg[o];
void build(int id,int l,int r){
	v[0][0][id]=r-l+1;
	if(l==r) return;
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
}
inline void ad(int id,int val){
	for(int i=0;i<2;++i) v[i][2][id]+=(2*v[i][1][id]*val+val*v[i][0][id]*val),v[i][1][id]+=v[i][0][id]*val;
	flg[id]+=val;
}
inline void pushdown(int id){ad(id<<1,flg[id]);ad((id<<1)|1,flg[id]);flg[id]=0;}
inline void upd(int id){for(int i=0;i<2;++i) for(int j=0;j<3;++j) v[i][j][id]=v[i][j][id<<1]+v[i][j][(id<<1)|1];}
void modify(int id,int ql,int qr,int val,int l=0,int r=E){
	if(ql<=l&&r<=qr){ad(id,val);return;}
	pushdown(id);
	int md=l+r>>1;
	if(ql<=md) modify(id<<1,ql,qr,val,l,md);
	if(md<qr) modify((id<<1)|1,ql,qr,val,md+1,r);
	upd(id);
}
void chg(int id,int pos,int val,int l=0,int r=E){
	if(l==r){for(int i=0;i<3;++i) v[1][i][id]+=val*v[0][i][id];return;}
	int md=l+r>>1;
	pushdown(id);
	if(pos<=md) chg(id<<1,pos,val,l,md);
	else chg((id<<1)|1,pos,val,md+1,r);
	upd(id);
}
int query(int id,int pos,int l=0,int r=E){
	if(l==r) return v[1][0][id];
	pushdown(id);
	int md=l+r>>1;
	return pos<=md?query(id<<1,pos,l,md):query((id<<1)|1,pos,md+1,r);
}
int main(){
	scanf("%d%d",&q,&d);
	build(1,0,E);
	for(int a;q--;printf("%lld\n",(v[1][2][1]-v[1][1][1])/2)){
		scanf("%d",&a);
		if(query(1,a)) modify(1,max(1,a-d),a-1,-1),chg(1,a,-1);
		else modify(1,max(1,a-d),a-1,1),chg(1,a,1);
	}
	return 0;
}