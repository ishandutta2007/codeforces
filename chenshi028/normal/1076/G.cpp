#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
inline void swp(int&a,int&b){a^=b^=a^=b;}
const int o=2e5+10;
int n,m,q;
struct mask{int ans[22];}C;
inline mask merge(int L,int MD,int R,mask A,mask B){
	for(int i=Max(1,MD+1-R+m),j;i<=m+1;++i)
		if(A.ans[j=Max(m+L-MD,B.ans[i])]<=m) C.ans[i]=A.ans[j];
		else C.ans[i]=Min(m,B.ans[i]+MD-L)+1;
	for(int i=Max(1,L-R+m);i<=MD-R+m;++i) C.ans[i]=A.ans[i+R-MD];
	return C;
}
struct segmenttree{
	int l,r;bool flg;mask a,b;
	inline void rev(){flg^=1;for(int i=m+1;i;--i) swp(a.ans[i],b.ans[i]);}
}nod[o*4];
void build(int id,int l,int r){
	nod[id].l=l;nod[id].r=r;nod[id].flg=0;
	if(l==r){
		nod[id].a.ans[m+1]=1;
		nod[id].a.ans[m]=nod[id].b.ans[m]=nod[id].b.ans[m+1]=m+1;
		return;
	}
	int md=l+r>>1;
	build(id<<1,l,md);build((id<<1)|1,md+1,r);
	nod[id].a=merge(nod[id].l,md,nod[id].r,nod[id<<1].a,nod[(id<<1)|1].a);
	nod[id].b=merge(nod[id].l,md,nod[id].r,nod[id<<1].b,nod[(id<<1)|1].b);
}
inline void pushdown(int id){if(nod[id].flg) nod[id<<1].rev(),nod[(id<<1)|1].rev(),nod[id].flg=0;}
void modify(int id,int l,int r){
	if(nod[id].l==l&&nod[id].r==r){nod[id].rev();return;}
	pushdown(id);
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) modify(id<<1,l,r);
	else if(md<l) modify((id<<1)|1,l,r);
	else modify(id<<1,l,md),modify((id<<1)|1,md+1,r);
	nod[id].a=merge(nod[id].l,md,nod[id].r,nod[id<<1].a,nod[(id<<1)|1].a);
	nod[id].b=merge(nod[id].l,md,nod[id].r,nod[id<<1].b,nod[(id<<1)|1].b);
}
mask query(int id,int l,int r){
	if(nod[id].l==l&&nod[id].r==r) return nod[id].a;
	pushdown(id);
	int md=nod[id].l+nod[id].r>>1;
	if(r<=md) return query(id<<1,l,r);
	if(md<l) return query((id<<1)|1,l,r);
	return merge(l,md,r,query(id<<1,l,md),query((id<<1)|1,md+1,r));
}
int opt,l,r,x;
int main(){
	read(n);read(m);read(q);
	build(1,1,n);
	for(int i=1;i<=n;++i){read(x);if(!(x&1)) modify(1,i,i);}
	while(q--){
		read(opt);read(l);read(r);
		if(opt==1){read(x);if(x&1) modify(1,l,r);}
		else if(query(1,l,r).ans[m+1]==1) printf("2\n");else printf("1\n");
	}
	return 0;
}