#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 102000;
const ll inf = 1e16;
int n,k,a[N];
ll f[N],g[N],sum;
int lp,rp,buc[N];
inline void ins(int p) {sum+=buc[a[p]]; ++buc[a[p]];}
inline void del(int p) {--buc[a[p]]; sum-=buc[a[p]];}
inline void dfs(int l, int r, int L, int R) {
	if (l>r) return;
	int mid=(l+r)>>1,M=min(R,mid-1); //[lp,rp] --> [] (L..M <--> mid)
	while (rp<mid) ins(++rp);
	while (lp>1+M) ins(--lp);
	while (lp<1+M) del(lp++);
	while (rp>mid) del(rp--);
	f[mid]=sum+g[M]; //lp,rp == [M+1,mid]
	per(i,M-1,L) {ins(--lp); if (sum+g[i]<f[mid]) {f[mid]=sum+g[i]; M=i;}}
	dfs(l,mid-1,L,M); dfs(mid+1,r,M,R);
}
int main() { //freopen("1.in","r",stdin);
	read(n); read(k); rep(i,1,n) read(a[i]);
	rep(i,1,n) g[i]=inf; g[0]=0;
	rep(i,1,k) {
		rep(i,0,n) f[i]=inf;
		lp=1;rp=0;sum=0;memset(buc,0,sizeof(buc)); 
		dfs(1,n,0,n-1);
		memcpy(g,f,sizeof(f));
	}
	printf("%lld",f[n]);
	return 0;
}