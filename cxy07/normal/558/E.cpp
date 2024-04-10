#pragma GCC optimize(2)

//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Q {
	int x,l,r;
	Q(int _x = 0,int _l = 0,int _r = 0) : l(_l),r(_r),x(_x) {}
	void read() {scanf("%d%d%d",&l,&r,&x);}
} q[MAXN];

int n,m;
int ask[MAXN],tmp1[MAXN],tmp2[MAXN];
int seg[MAXN << 2],tag[MAXN << 2];
char s[MAXN],ans[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void pushdown(int x,int l,int r) {
	if(tag[x] != -1) {
		int mid = (l + r) >> 1;
		seg[x << 1] = tag[x] * (mid - l + 1);
		seg[x << 1 | 1] = tag[x] * (r - mid);
		tag[x << 1] = tag[x];
		tag[x << 1 | 1] = tag[x];
		tag[x] = -1;
	}
}

void pushup(int x) {seg[x] = seg[x << 1] + seg[x << 1 | 1];}

void build(int x,int l,int r,int v) {
	tag[x] = -1;
	if(l == r) {
		seg[x] = (s[l] >= v ? 1 : 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1,l,mid,v);
	build(x << 1 | 1,mid + 1,r,v);
	pushup(x);
}

int query(int x,int l,int r,int L,int R) {
	if(L > R) return 0;
	if(L <= l && r <= R) return seg[x];
	int mid = (l + r) >> 1,res = 0;
	pushdown(x,l,r);
	if(L <= mid) res += query(x << 1,l,mid,L,R);
	if(R > mid) res += query(x << 1 | 1,mid + 1,r,L,R);
	return res;
}

void update(int x,int l,int r,int L,int R,int v) {
	if(L > R) return;
	if(L <= l && r <= R) {
		seg[x] = v * (r - l + 1);
		tag[x] = v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(L <= mid) update(x << 1,l,mid,L,R,v);
	if(R > mid) update(x << 1 | 1,mid + 1,r,L,R,v);
	pushup(x);
}

void solve(int l,int r,int L,int R) {//ask[L-R]  [l,r]
	if(l > r || L > R) return;
	if(l == r) {
		for(int i = L;i <= R; ++i) ans[ask[i]] = l;
		return;
	}
	int mid = (l + r) >> 1,cnt1 = 0,cnt2 = 0;
	build(1,1,n,mid);
	for(int i = 1,ll,rr,x,cnt;i <= m; ++i) {
		ll = q[i].l,rr = q[i].r,x = q[i].x;
		cnt = query(1,1,n,ll,rr);
		update(1,1,n,ll,rr,0);
		if(x) update(1,1,n,rr - cnt + 1,rr,1);
		else update(1,1,n,ll,ll + cnt - 1,1);
	}
	for(int i = L;i <= R; ++i) {
		int v = query(1,1,n,ask[i],ask[i]);
		if(v) tmp2[++cnt2] = ask[i];
		else tmp1[++cnt1] = ask[i];
	}
	for(int i = L;i <= L + cnt1 - 1; ++i) ask[i] = tmp1[i - L + 1];
	for(int i = L + cnt1;i <= R; ++i) ask[i] = tmp2[i - L - cnt1 + 1];
	solve(l,mid,L,L + cnt1 - 1);
	solve(mid + 1,r,L + cnt1,R);
}

signed main () {
#ifdef FILE
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
#endif
	read(n); read(m);
	scanf("%s",s + 1);
	for(int i = 1;i <= m; ++i) q[i].read();
	for(int i = 1;i <= n; ++i) ask[i] = i;
	solve('a','z' + 1,1,n);
	for(int i = 1;i <= n; ++i) putchar((char)ans[i] - 1);
	putchar('\n');
	return 0;
}