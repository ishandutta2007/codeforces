#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n; char s[200010];

struct D{
	D *f,*ch[2];  // null->f chg; ch used
	int c,s,t;  // col siz  // c chg; s used
	
	inline bool isroot(){return f->ch[0]!=this&&f->ch[1]!=this;}
	inline bool which(){return f->ch[1]==this;}
	inline void pushdown(){
		ch[0]->c=ch[1]->c=c;
	}
	inline void pushup(){
		s=ch[0]->s+t+ch[1]->s;
	}
	inline void rotate(){
		bool w=which()^1;
		D *y=f; f=y->f;
		if (!y->isroot()) f->ch[y->which()]=this;
		y->ch[w^1]=ch[w]; ch[w]->f=y;
		y->f=this; ch[w]=y;
		y->pushup(); pushup();
	}
	void flash(){if (!isroot()) f->flash(); pushdown();}
	void splay(){
		flash();
		while (!isroot())
			if (f->isroot()) rotate();
			else if (which()^f->which()) rotate(),rotate();
			else f->rotate(),rotate();
	}
	
	D* access(D*);
	void makeroot();
	void link(D*);
}d[400010],*null=new D();

P stk[200010]; int top;  // {sz,col}

int work(int x){
	int res=1,l=1,p=1;
	if (stk[top].fi==0) --top;
	reverse(stk+1,stk+top+1);
	while (top&&stk[top].se==0) --top;
	rep(i,1,top) stk[i].fi+=stk[i-1].fi;
	while (1){
		while (p<=top&&stk[p].fi<l) ++p;
		if (p>top) break;
		const int dlt=stk[p].se-x;
		int t=(stk[p].fi-l)/dlt+1;
		l+=t*dlt; res+=t;
	}
	return res;
}

D* D::access(D *lst=null){
	splay(); pushdown();
	
	ch[1]=null; pushup();
	stk[++top]=P(s,c);
	
	ch[1]=lst; pushup();
	return f==null?this:f->access(this);
}
void D::link(D *t){
	f=t;
}


namespace S{  // SAM

struct C{
	int f,t[26];
	int p,l;
	bool e;
}c[400010];

int idtot=1,p[200010];

int ins(int lst,int id,int pos){
	int x=++idtot; c[x].p=pos,c[x].l=c[lst].l+1,c[x].e=1;
	for (;lst&&!c[lst].t[id];c[lst].t[id]=x,lst=c[lst].f);
	if (!lst) return c[x].f=1,x;
	int nxt=c[lst].t[id];
	if (c[nxt].l==c[lst].l+1) return c[x].f=nxt,x;
	int w=++idtot; c[w].f=c[nxt].f,memcpy(c[w].t,c[nxt].t,26<<2);
	c[w].p=pos,c[w].l=c[lst].l+1,c[w].e=0;
	c[x].f=c[nxt].f=w;
	for (;lst&&c[lst].t[id]==nxt;c[lst].t[id]=w,lst=c[lst].f);
	return x;
}

void build(){
	rep(i,1,idtot) d[i]=*null,d[i].t=c[i].l-c[c[i].f].l;
	rep(i,2,idtot) d[i].link(d+c[i].f);
}

}
using namespace S;


void solve(){
	n=read(); scanf("%s",s+1); p[n+1]=1;
	per(i,1,n) p[i]=ins(p[i+1],s[i]-'a',i);
	build();
	int ans=0;
	per(i,1,n){
		top=0;
		auto v=d[p[i]].access();
		ans=max(ans,work(i));
		v->c=i;
	}
	printf("%d\n",ans);
}
int main()
{
	*null=(D){null,{null,null},0,0,0};
	for (int T=1;T--;) solve();
	return 0;
}