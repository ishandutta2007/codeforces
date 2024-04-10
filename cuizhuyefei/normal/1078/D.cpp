#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 303000;
int n,a[N];
struct QaQ{
	Pii a[N<<2],seg[N];int m;
	inline Pii merge(Pii a,Pii b){return Pii(min(a.fi,b.fi),max(a.se,b.se));}
	inline Pii query(int l,int r){
		Pii res(1e9,0);l=l+m-1;r=r+m+1;
		while((l>>1)!=(r>>1)){
			if(!(l&1))res=merge(res,a[l+1]);
			if(r&1)res=merge(res,a[r-1]);l>>=1;r>>=1;
		}
		return res;
	}
	inline void init(){
		for(m=1;m<=3*n+1;m<<=1);
		rep(i,1,3*n)a[m+i]=seg[i];
		per(i,m-1,1)a[i]=merge(a[i<<1],a[i<<1|1]);
	}
}qaq[17];
inline void fix(Pii &a){
	umax(a.fi,1);umin(a.se,3*n);
}
int main() {
	read(n);rep(i,1,n)read(a[i]),a[n+i]=a[n+n+i]=a[i];
	rep(i,1,3*n)qaq[0].seg[i]=Pii(i-a[i],i+a[i]),fix(qaq[0].seg[i]);
	qaq[0].init();
	rep(j,1,16){
		rep(i,n+1,n+n){
			Pii tmp=qaq[j-1].query(qaq[j-1].seg[i].fi,qaq[j-1].seg[i].se);
			qaq[j].seg[i]=tmp;
			qaq[j].seg[i-n]=Pii(tmp.fi-n,tmp.se-n);
			qaq[j].seg[i+n]=Pii(tmp.fi+n,tmp.se+n);
		}
		rep(i,1,3*n)fix(qaq[j].seg[i]);
		qaq[j].init();
	}
	rep(i,n+1,n+n){
		int l=i,r=i,res=0;
		per(j,16,0){
			Pii now=qaq[j].query(l,r);
			if(now.se-now.fi+1<n)res+=1<<j,l=now.fi,r=now.se;
		}
		printf("%d ",n>1?res+1:0);
	}
	return 0;
}