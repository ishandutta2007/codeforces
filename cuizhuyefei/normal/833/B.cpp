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
const int N = 35005,inf=0x3f3f3f3f;
int n,k,a[N],dp[55][N];
int val[N<<2],lzy[N<<2],tt[N],pos[N];
void build(int k, int l, int r){
	lzy[k]=0;
	if(l==r){
		val[k]=tt[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	val[k]=max(val[k<<1],val[k<<1|1]);
}
void pushdown(int k){
	if(lzy[k]){
		lzy[k<<1]+=lzy[k];val[k<<1]+=lzy[k];
		lzy[k<<1|1]+=lzy[k];val[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
void modify(int k, int l,int r, int x, int L, int R){
	if(l==L&&r==R){
		val[k]+=x;lzy[k]+=x;return;
	}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)modify(k<<1,l,r,x,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,x,mid+1,R);
	else modify(k<<1,l,mid,x,L,mid),modify(k<<1|1,mid+1,r,x,mid+1,R);
	val[k]=max(val[k<<1],val[k<<1|1]);
}
int qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return val[k];
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)return qry(k<<1,l,r,L,mid);
	else if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
	return max(qry(k<<1,l,mid,L,mid),qry(k<<1|1,mid+1,r,mid+1,R));
}
int main() {
	read(n);read(k);
	rep(i,1,n)read(a[i]);
	rep(i,0,k)rep(j,0,n)dp[i][j]=-inf;
	dp[0][0]=0;
	rep(j,1,k){
		rep(i,1,n)tt[i]=dp[j-1][i-1];
		build(1,1,n);
		memset(pos,0,sizeof(pos));
		rep(i,1,n){
			modify(1,pos[a[i]]+1,i,1,1,n);
			pos[a[i]]=i;
			dp[j][i]=qry(1,1,i,1,n);
		}
	}
	cout<<dp[k][n];
	return 0;
}