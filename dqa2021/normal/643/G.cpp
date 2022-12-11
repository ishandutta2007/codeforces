#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m,p,q;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct C{
	int v,t;
};
struct E{
	C c[5];
	int tg;
	void clear(){
		for (int i=0;i<q;i++) c[i].t=0;
	}
}e[1<<19];

void merge(E &x,const E &L,E R){
	//puts("merge");
	//for (int i=0;i<q;i++) printf("L %d: %d, %d\n",i,L.c[i].v,L.c[i].t);
	//for (int i=0;i<q;i++) printf("R %d: %d, %d\n",i,R.c[i].v,R.c[i].t);
	for (int i=0;i<q;i++) x.c[i]=L.c[i];
	for (int i=0;i<q;i++) if (R.c[i].t){
		bool flg=0;
		for (int j=0;j<q;j++) if (x.c[j].v==R.c[i].v){
			x.c[j].t+=R.c[i].t; flg=1; break;
		}
		if (flg) continue;
		for (int j=0;j<q;j++) if (!x.c[j].t){
			x.c[j]=R.c[i]; flg=1; break;
		}
		if (flg) continue;
		int s=R.c[i].t;
		for (int j=0;j<q;j++) s=min(s,x.c[j].t);
		for (int j=0;j<q;j++) x.c[j].t-=s;
		R.c[i].t-=s; if (R.c[i].t) i--;
	}
}
inline void pushdown(int x,int l,int r){
	if (!~e[x].tg) return; int v=e[x].tg; e[x].tg=-1;
	e[ls].clear(); e[ls].c[0]=(C){v,mid-l+1}; e[ls].tg=v;
	e[rs].clear(); e[rs].c[0]=(C){v,r-mid}; e[rs].tg=v;
}
void build(int x,int l,int r){
	e[x].tg=-1;
	if (l==r) return e[x].c[0]=(C){read(),1},void();
	build(ls,l,mid); build(rs,mid+1,r);
	merge(e[x],e[ls],e[rs]);
}
void update(int x,int l,int r,int ql,int qr,int v){
	if (ql<=l&&r<=qr){
		e[x].tg=v;
		e[x].clear();
		e[x].c[0]=(C){v,r-l+1};
		return;
	}
	pushdown(x,l,r);
	if (ql<=mid) update(ls,l,mid,ql,qr,v);
	if (mid<qr) update(rs,mid+1,r,ql,qr,v);
	merge(e[x],e[ls],e[rs]);
}
E query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return e[x];
	pushdown(x,l,r);
	if (qr<=mid) return query(ls,l,mid,ql,qr);
	if (mid<ql) return query(rs,mid+1,r,ql,qr);
	E a=query(ls,l,mid,ql,qr),b,c=query(rs,mid+1,r,ql,qr);
	merge(b,a,c);
	return b;
}

int main()
{
	n=read(),m=read(),p=read(),q=100/p;
	build(1,1,n);
	while (m--){
		if (read()&1){
			int l=read(),r=read(),v=read();
			update(1,1,n,l,r,v);
		}
		else{
			static int s[10],top; top=0;
			int l=read(),r=read();
			E t=query(1,1,n,l,r);
			for (int i=0;i<q;i++) if (t.c[i].t) s[++top]=t.c[i].v;
			printf("%d",top); for (int i=1;i<=top;i++) printf(" %d",s[i]); puts("");
		}
	}
	return 0;
}