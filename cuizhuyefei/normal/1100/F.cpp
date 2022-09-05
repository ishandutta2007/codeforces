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
const int N = 500050;
int n,a[N],ans[N],f[N][20],g[N][20];
struct Que{
	int l,r,idx;
}que[N];
inline void ins(int a[20], int x){
	per(i,19,0)if(x>>i&1)
		if(!a[i]){a[i]=x;break;}
		else x^=a[i];
}
inline void solve(int l, int r, const vector<Que>&q){
	if(!SZ(q))return;
	if(l==r){rep(i,0,SZ(q)-1)ans[q[i].idx]=a[l];return;}
	int mid=(l+r)>>1;//[l,mid] [mid+1,r]
	memset(f[mid+1],0,sizeof(f[mid+1]));
	per(i,mid,l){
		memcpy(f[i],f[i+1],sizeof(f[i+1]));ins(f[i],a[i]);
	}
	memset(g[mid],0,sizeof(g[mid]));
	rep(i,mid+1,r){
		memcpy(g[i],g[i-1],sizeof(g[i-1]));ins(g[i],a[i]);
	}
	vector<Que>A,B;
	rep(i,0,SZ(q)-1)
		if(q[i].r<=mid)A.pb(q[i]);
		else if(q[i].l>mid)B.pb(q[i]);
		else{
			int a[20]={0};memcpy(a,f[q[i].l],4*20);
			rep(j,0,19)if(g[q[i].r][j]){if(!a[j])a[j]=g[q[i].r][j];else ins(a,g[q[i].r][j]);}
			int res=0;per(j,19,0)if((res^a[j])>res)res^=a[j];ans[q[i].idx]=res;
		}
	solve(l,mid,A);solve(mid+1,r,B);
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	int q;read(q);
	rep(i,1,q)read(que[i].l),read(que[i].r),que[i].idx=i;
	static vector<Que>tmp;rep(i,1,q)tmp.pb(que[i]);solve(1,n,tmp);
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}