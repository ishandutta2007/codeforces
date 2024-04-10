#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
const int S=250;
const int M1=998244353,M2=1004535809,B1=123456,B2=145623;
struct P{
	int p1,p2;
}p[100010];
int upd(int x,int Mod){return x+(x>>31&Mod);}
struct H{
	int h1,h2;
};
H operator+(H x,H y){return (H){upd(x.h1+y.h1-M1,M1),upd(x.h2+y.h2-M2,M2)};}
H operator-(H x,H y){return (H){upd(x.h1-y.h1,M1),upd(x.h2-y.h2,M2)};}
H operator*(H x,P y){return (H){int(1LL*x.h1*y.p1%M1),int(1LL*x.h2*y.p2%M2)};}
bool operator==(H x,H y){return x.h1==y.h1&&x.h2==y.h2;}


int n,m,q;
int w[100010];
struct B{
	bool r,v;  //rebuild? valid?
	H R[256],L[256]; int Rlen,Llen;  //S
}blk[512];  //n/S
struct Rec{
	H *s; int len;
}rec[100010]; int top; int totlen;
void build(int l,int r,B &x){
	x.r=0,x.v=1,x.Rlen=x.Llen=0;
	static int P[100010],Q[100010],Ptot,Qtot; Ptot=Qtot=0;
	for (int i=l;i<=r;i++){
		if (w[i]>0) P[++Ptot]=w[i];
		else{
			if (!Ptot) Q[++Qtot]=-w[i];
			else if (P[Ptot]!=-w[i]) return x.v=0,void();
			else --Ptot;
		}
	}
	reverse(Q+1,Q+Qtot+1);
	for (int i=1;i<=Qtot;i++){
		++x.Rlen; x.R[x.Rlen]=x.R[x.Rlen-1]*p[1]+(H){Q[i],Q[i]};
	}
	for (int i=1;i<=Ptot;i++){
		++x.Llen; x.L[x.Llen]=x.L[x.Llen-1]*p[1]+(H){P[i],P[i]};
	}
}
bool ins(B &R){
	if (R.Rlen>totlen) return 0;
	int pos=R.Rlen;
	while (pos){
		int t=min(rec[top].len,pos);
		H *s=rec[top].s; int len=rec[top].len;
		if (!(R.R[pos]-R.R[pos-t]*p[t]==s[len]-s[len-t]*p[t])) return 0;
		pos-=t; rec[top].len-=t; totlen-=t;
		if (!rec[top].len) top--;
	}
	if (R.Llen) rec[++top]=(Rec){R.L,R.Llen},totlen+=R.Llen;
	return 1;
}
bool ask(int l,int r){
	if ((r-l+1)&1) return 0;
	int a=(l-1)/S,b=(r-1)/S;
	if (a==b){
		static int stk[100010],top; top=0;
		for (int i=l;i<=r;i++){
			if (w[i]>0) stk[++top]=w[i];
			else{
				if (!top||stk[top]!=-w[i]) return 0;
				--top;
			}
		}
		return top?0:1;
	}
	static B L,R;
	build(l,(a+1)*S,L);
	if (!L.v||L.Rlen) return 0;
	totlen=0; top=0;
	if (L.Llen) rec[top=1]=(Rec){L.L,L.Llen},totlen=L.Llen;
	for (int i=a+1;i<b;i++){
		if (blk[i].r) build(i*S+1,(i+1)*S,blk[i]);
		if (blk[i].v^1) return 0;
		if (!ins(blk[i])) return 0;
	}
	build(b*S+1,r,R);
	if (R.v^1) return 0;
	if (!ins(R)) return 0;
	return !top;
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	n=read(),m=read();
	for (int i=1;i<=n;i++) w[i]=read();
	p[0].p1=p[0].p2=1;
	for (int i=1;i<=n;i++){
		p[i]=(P){int(1LL*p[i-1].p1*B1%M1),int(1LL*p[i-1].p2*B2%M2)};
	}
	for (int i=0;i*S+1<=n;i++) blk[i].r=1;
	q=read();
	while (q--){
		if (read()&1){
			int x=read(),v=read();
			w[x]=v; blk[(x-1)/S].r=1;
			continue;
		}
		int l=read(),r=read();
		puts(ask(l,r)?"yes":"no");
	}
	return 0;
}