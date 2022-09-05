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
const int N = 666666;
int n,a[N],q,OP[N],A[N],B[N],sz,v[N],ans[N];
int hz[N],pos[N];
int main() {
	read(n);rep(i,1,n)read(a[i]);read(q);
	rep(i,1,q){
		read(OP[i]);read(A[i]);
		if(OP[i]==1)read(B[i]),pos[A[i]]=i;
	}
	per(i,q,1){
		hz[i]=hz[i+1];if(OP[i]==2)umax(hz[i],A[i]);
	}
	
	rep(i,1,n){
		int ans=pos[i]?max(B[pos[i]],hz[pos[i]+1]):max(a[i],hz[1]);
		printf("%d ",ans);
	}
	return 0;
}