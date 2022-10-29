#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() { //Don't to use it in interactive problems!!!
	static char *p1, *p2, buf[1<<23];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<23, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline void read(char *s) {
	char c; while (isspace(c=getc()));
	while (!isspace(c)) (*s++)=c, c=getc();
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=3e5+7, dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0}, mod=998244353;
const char ch[]={'R', 'L', 'D', 'U'};
const ll INF=1e15;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int add(int x, int y) {return inc(x, y), x;}
inline int sub(int x, int y) {return dec(x, y), x;}
inline int qpow(int a, ll b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
int n, m, p, q;
vector<ll>w[N];
vector<bool>vis[N];
string a[N];
/*
inline ll calc(int i, int j) {
	if (i<0 || j<0 || i>=n || j>=m || vis[i][j]) return INF;
	if (~w[i][j]) return w[i][j];
	ll &v=w[i][j]; v=INF;
	if (a[i][j]=='.') return v=0;
	if (a[i][j]=='#') return v=INF;
	vis[i][j]=true;
	if (a[i][j]=='L') ckmin(v, min(p+min(calc(i-1, j+1), calc(i+1, j+1)), q+calc(i, j+2)));
	else if (a[i][j]=='R') ckmin(v, min(p+min(calc(i-1, j-1), calc(i+1, j-1)), q+calc(i, j-2)));
	else if (a[i][j]=='U') ckmin(v, min(p+min(calc(i+1, j-1), calc(i+1, j+1)), q+calc(i+2, j)));
	else ckmin(v, min(p+min(calc(i-1, j-1), calc(i-1, j+1)), q+calc(i-2, j)));
	vis[i][j]=false;
	return v;
}*/
inline void work() {
	cin>>n>>m>>p>>q;
	for (int i=0; i<n; i++) cin>>a[i];
	for (int i=0; i<n; i++) w[i].resize(m, INF), vis[i].resize(m, false);
	priority_queue<pair<ll, pair<int, int> > >Q;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) if (a[i][j]=='.') w[i][j]=0, Q.push({0, {i, j}});
	while (!Q.empty()) {
		int i=Q.top().se.fi, j=Q.top().se.se; Q.pop();
		if (vis[i][j]) continue; vis[i][j]=true;
		for (int k=0; k<4; k++) {
			int x=i+dx[k], y=j+dy[k]; ll v=w[i][j];
			if (x<0 || y<0 || x>=n || y>=m) continue;
			char c=a[x][y];
			if (c=='.' || c=='#' || c==ch[k]) continue;
			if (!k) { //ri
				if (c=='L') y++, v+=q;
				else if (c=='U') x++, v+=p;
				else x--, v+=p;
			} else if (k==1) { //le
				if (c=='R') y--, v+=q;
				else if (c=='U') x++, v+=p;
				else x--, v+=p;
			} else if (k==2) { //dw
				if (c=='U') x++, v+=q;
				else if (c=='L') y++, v+=p;
				else y--, v+=p;
			} else { //up
				if (c=='D') x--, v+=q;
				else if (c=='L') y++, v+=p;
				else y--, v+=p;
			}
			if (x<0 || y<0 || x>=n || y>=m) continue;
			if (w[x][y]>v) w[x][y]=v, Q.push({-v, {x, y}});
		}
	}
	//for (int i=0; i<n; i++)
	//	for (int j=0; j<m; j++) calc(i, j);//, cout<<w[i][j]<<" \n"[j==m-1];
	ll ans=INF;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			for (int k=0; k<4; k++) {
				int x=i+dx[k], y=j+dy[k];
				if (x<0 || y<0 || x>=n || y>=m) continue;
				ckmin(ans, w[i][j]+w[x][y]);
			}
	if (ans==INF) ans=-1;
	printf("%lld\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int test=1; //read();
	while (test--) work();
	return 0;
}