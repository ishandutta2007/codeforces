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
const int N = 102000;
int n,q,OP[N],A[N],B[N],C[N],D[N],ans[N],v[5050][10500];
void caozuo(int &x, int &y, int a, int b){
	if(a)x=n-x+1;if(b)y=n-y+1;
}
void caozuo(int x, int y){
	rep(i,1,q)if(OP[i]==2)caozuo(A[i],B[i],x,y);
	else caozuo(B[i],C[i],x,y);
}
struct ONE{
	int v[10200];
	void init(){memset(v,0,sizeof(v));}
	inline void modify(int p){while(p)v[p]++,p-=p&-p;}
	inline int qry(int p){int r=0;while(p<=n*2)r+=v[p],p+=p&-p;return r;}
}tree;
inline void modify(int p1, int p2){
	while(p1){
		int p=p2;while(p)v[p1][p]++,p-=p&-p;
		p1-=p1&-p1;
	}
}
inline int qry(int p1, int p2){
	int r=0;
	while(p1<=n){
		int p=p2;while(p<=n*2)r+=v[p1][p],p+=p&-p;
		p1+=p1&-p1;
	}
	return r;
}
void solve(int tp){
	tree.init();memset(v,0,sizeof(v));
	rep(i,1,q)if(OP[i]==1){
		if(A[i]==tp){
			int x=B[i],y=C[i],l=D[i];
			tree.modify(x+y+l);
			modify(x-1,x+y+l);
		}
	}
	else{
		int x=A[i],y=B[i];
		ans[i]+=tree.qry(x+y);
		ans[i]-=qry(x,x+y);
	}
	memset(v,0,sizeof(v));
	rep(i,1,q)if(OP[i]==1){
		if(A[i]==tp){
			int x=B[i],y=C[i],l=D[i];
			modify(y-1,x+y+l);
		}
	}
	else{
		int x=A[i],y=B[i];
		ans[i]-=qry(y,x+y);
	}
	memset(v,0,sizeof(v));
	rep(i,1,q)if(OP[i]==1){
		if(A[i]==tp){
			int x=B[i],y=C[i],l=D[i];
			modify(x-1,y-1);
		}
	}
	else{
		int x=A[i],y=B[i];
		ans[i]+=qry(x,y);
	}
}
int main() {
	read(n);read(q);
	rep(i,1,q){
		read(OP[i]);
		if(OP[i]==2)read(A[i]),read(B[i]);
		else read(A[i]),read(B[i]),read(C[i]),read(D[i]);
	}
	solve(1);
	caozuo(0,1);solve(2);caozuo(0,1);
	caozuo(1,0);solve(3);caozuo(1,0);
	caozuo(1,1);solve(4);caozuo(1,1);
	rep(i,1,q)if(OP[i]==2)printf("%d\n",ans[i]);
	return 0;
}