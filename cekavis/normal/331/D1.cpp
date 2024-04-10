#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long
// #define int ll

inline char read() {
	// return getchar();
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void print(pair<int,int> x){
	print(x.first), print(' '), print(x.second), print('\n');
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005, M = 52;
const ll inf = 1e16;
int n, m, q, x[N], y[N], xx[N], yy[N], X[N], Y[N], fa[N], fa1[N], f1[N], s[N<<2], f[N][M];
ll T[N], ga[N], g[N][M];
char opt[N], op[N];
vector<int> a[N], b[N], c[N];
void build(int l, int r, int t){
	s[t]=0;
	if(l==r) return;
	int mid=(l+r)>>1, k=t<<1;
	build(l, mid, k), build(mid+1, r, k|1);
}
void change(int l, int r, int t, int L, int R, int x){
	if(L<=l && r<=R) return (void)(s[t]=x);
	int mid=(l+r)>>1, k=t<<1;
	if(s[t]) s[k]=s[k|1]=s[t], s[t]=0;
	if(L<=mid) change(l, mid, k, L, R, x);
	if(R>mid) change(mid+1, r, k|1, L, R, x);
}
int query(int l, int r, int t, int x){
	if(l==r || s[t]) return s[t];
	int mid=(l+r)>>1, k=t<<1;
	return (x<=mid?query(l, mid, k, x):query(mid+1, r, k|1, x));
}
inline pair<int,int> solve(pair<int,int> x, char o, ll t){
	int a=x.first, b=x.second;
	if(o=='L') a=max(0ll, a-t);
	if(o=='R') a=min((ll)m, a+t);
	if(o=='D') b=max(0ll, b-t);
	if(o=='U') b=min((ll)m, b+t);
	return make_pair(a, b);
}
signed main() {
	// freopen("duan.in", "r", stdin);
	// freopen("duan.out", "w", stdout);
	read(n), read(m);
	for(int i=1; i<=n; ++i){
		read(x[i]), read(y[i]), read(xx[i]), read(yy[i]);
		if(x[i]==xx[i]) a[x[i]].push_back(i), op[i]=(y[i]>yy[i]?'D':'U');
		else b[x[i]].push_back(i), b[xx[i]].push_back(i), op[i]=(x[i]>xx[i]?'L':'R');
	}
	read(q);
	for(int i=1; i<=q; ++i){
		read(X[i]), read(Y[i]);
		while(isspace(opt[i]=read()));
		read(T[i]);
		// if(i==950 && x[7]==3 && y[7]==8 && xx[7]==2 && yy[7]==8)
		// 	printf(">> %d %d %c %lld\n", X[i], Y[i], opt[i], T[i]);
	}
	// work r->l
	for(int i=1; i<=q; ++i) if(opt[i]=='R') c[X[i]].push_back(i);
	build(0, m, 1);
	for(int i=m; ~i; --i){
		for(int j:a[i]) change(0, m, 1, min(y[j], yy[j]), max(y[j], yy[j]), j);
		for(int j:b[i])
			if(x[j]>xx[j]) change(0, m, 1, y[j], y[j], j);
			else f[j][0]=query(0, m, 1, y[j]), g[j][0]=(f1[j]=abs(xx[f[j][0]]-xx[j]))+abs(yy[f[j][0]]-y[j]);
		for(int j:c[i]){
			fa[j]=query(0, m, 1, Y[j]), ga[j]=abs(xx[fa[j]]-X[j])+abs(yy[fa[j]]-Y[j]);
			fa1[j]=(x[fa[j]]==xx[fa[j]]?abs(xx[fa[j]]-X[j]):max(xx[fa[j]]-X[j], 0));
		}
	}
	// work l->r
	for(int i=0; i<=m; ++i) c[i].clear();
	for(int i=1; i<=q; ++i) if(opt[i]=='L') c[X[i]].push_back(i);
	build(0, m, 1);
	for(int i=0; i<=m; ++i){
		for(int j:a[i]) change(0, m, 1, min(y[j], yy[j]), max(y[j], yy[j]), j);
		for(int j:b[i])
			if(x[j]<xx[j]) change(0, m, 1, y[j], y[j], j);
			else f[j][0]=query(0, m, 1, y[j]), g[j][0]=(f1[j]=abs(xx[j]-xx[f[j][0]]))+abs(yy[f[j][0]]-y[j]);
		for(int j:c[i]){
			fa[j]=query(0, m, 1, Y[j]), ga[j]=abs(X[j]-xx[fa[j]])+abs(yy[fa[j]]-Y[j]);
			fa1[j]=(x[fa[j]]==xx[fa[j]]?abs(xx[fa[j]]-X[j]):max(X[j]-xx[fa[j]], 0));
		}
	}
	// work u->d
	for(int i=0; i<=m; ++i) c[i].clear(), a[i].clear(), b[i].clear();
	for(int i=1; i<=n; ++i)
		if(y[i]==yy[i]) a[y[i]].push_back(i);
		else b[y[i]].push_back(i), b[yy[i]].push_back(i);
	for(int i=1; i<=q; ++i) if(opt[i]=='U') c[Y[i]].push_back(i);
	build(0, m, 1);
	for(int i=m; ~i; --i){
		for(int j:a[i]) change(0, m, 1, min(x[j], xx[j]), max(x[j], xx[j]), j);
		for(int j:b[i])
			if(y[j]>yy[j]) change(0, m, 1, x[j], x[j], j);
			else f[j][0]=query(0, m, 1, x[j]), g[j][0]=(f1[j]=abs(yy[f[j][0]]-yy[j]))+abs(xx[f[j][0]]-x[j]);
		for(int j:c[i]){
			fa[j]=query(0, m, 1, X[j]), ga[j]=(fa1[j]=abs(yy[fa[j]]-Y[j]))+abs(xx[fa[j]]-X[j]);
			fa1[j]=(x[fa[j]]==xx[fa[j]]?max(yy[fa[j]]-Y[j], 0):abs(yy[fa[j]]-Y[j]));
		}
	}
	// work d->u
	for(int i=0; i<=m; ++i) c[i].clear();
	for(int i=1; i<=q; ++i) if(opt[i]=='D') c[Y[i]].push_back(i);
	build(0, m, 1);
	for(int i=0; i<=m; ++i){
		for(int j:a[i]) change(0, m, 1, min(x[j], xx[j]), max(x[j], xx[j]), j);
		for(int j:b[i])
			if(y[j]<yy[j]) change(0, m, 1, x[j], x[j], j);
			else f[j][0]=query(0, m, 1, x[j]), g[j][0]=(f1[j]=abs(yy[j]-yy[f[j][0]]))+abs(xx[f[j][0]]-x[j]);
		for(int j:c[i]){
			fa[j]=query(0, m, 1, X[j]), ga[j]=(fa1[j]=abs(Y[j]-yy[fa[j]]))+abs(xx[fa[j]]-X[j]);
			fa1[j]=(x[fa[j]]==xx[fa[j]]?max(Y[j]-yy[fa[j]], 0):abs(yy[fa[j]]-Y[j]));
		}
	}

	// printf(">> %lld %lld %lld %lld\n", g[1][0], g[2][0], g[3][0], g[4][0]);
	//
	for(int j=1; j<=50; ++j) for(int i=1; i<=n; ++i)
		f[i][j]=f[f[i][j-1]][j-1], g[i][j]=min(inf, g[i][j-1]+g[f[i][j-1]][j-1]);
	for(int i=1; i<=q; ++i){
		if(!fa[i] || T[i]<fa1[i]) print(solve(make_pair(X[i], Y[i]), opt[i], T[i]));
		else if(T[i]<ga[i]) print(solve(solve(make_pair(X[i], Y[i]), opt[i], fa1[i]), op[fa[i]], T[i]-fa1[i]));
		else{
			T[i]-=ga[i];
			int now=fa[i];
			// printf(">> %d %d\n", ga[i], now);
			for(int j=50; ~j; --j) if(f[now][j] && g[now][j]<=T[i]) T[i]-=g[now][j], now=f[now][j];
			// if(i==3) printf(">> %lld %d\n", T[i], f1[now]);
			if(!f[now][0] || T[i]<f1[now]) print(solve(make_pair(xx[now], yy[now]), op[now], T[i]));
			else print(solve(solve(make_pair(xx[now], yy[now]), op[now], f1[now]), op[f[now][0]], T[i]-f1[now]));
		}
	}
	return flush(), 0;
}