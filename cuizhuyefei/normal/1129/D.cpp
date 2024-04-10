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
const int N = 102000, M = 360, mo = 998244353;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
int n,m,a[N],c[N],pre[N],pos[N],dp[N],ans;
int lzy[N/M+2],buc[N/M+2][N],bel[N],val[N],bg[N],ed[N];
inline void modify(int k, int x){
	if(x>0){if(m-lzy[k]>=0)sub(ans,buc[k][m-lzy[k]]);}
	else{if(m-lzy[k]+1>=0)add(ans,buc[k][m-lzy[k]+1]);}
	lzy[k]+=x;
}
inline void pushdown(int k){
	if(!lzy[k])return;
	rep(i,bg[k],ed[k])buc[k][c[i]]=0;
	rep(i,bg[k],ed[k])c[i]+=lzy[k];lzy[k]=0;
	rep(i,bg[k],ed[k])add(buc[k][c[i]],val[i]);
}
inline void modify(int k, int l, int r, int x){
	rep(i,bg[k],ed[k])buc[k][c[i]]=0;
	if(lzy[k]){rep(i,bg[k],ed[k])c[i]+=lzy[k];lzy[k]=0;}
	rep(i,l,r){
		if(c[i]<=m)sub(ans,val[i]);
		c[i]+=x;if(c[i]<=m)add(ans,val[i]);
	}
	rep(i,bg[k],ed[k])add(buc[k][c[i]],val[i]);
}
inline void modify(int l,int r, int x){
	int L=bel[l],R=bel[r];
	if(L==R){modify(L,l,r,x);}
	else{
		modify(L,l,ed[L],x);modify(R,bg[R],r,x);
		rep(i,L+1,R-1)modify(i,x);
	}
}
int main() {
	read(n);read(m);rep(i,1,n)read(a[i]);
	rep(i,1,n)bel[i]=i/M,ed[i/M]=i;
	per(i,n,1)bg[i/M]=i;
	rep(i,1,n){
		pre[i]=pos[a[i]];pos[a[i]]=i;
	}
	dp[0]=1;
	rep(i,1,n){
		val[i]=dp[i-1];if(c[i]<=m)add(ans,val[i]);
		pushdown(bel[i]);//1.val[i]-->dp[i-1]
		modify(pre[i]+1,i,1);
		if(pre[i])modify(pre[pre[i]]+1,pre[i],-1);
		dp[i]=ans;
	}
	printf("%d",dp[n]);
	return 0;
}