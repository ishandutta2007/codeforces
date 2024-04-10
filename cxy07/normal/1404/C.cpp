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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Q {
	int x,y,id;
	bool operator < (const Q &b) const {return x > b.x;}
} q[MAXN];

int n,m,ans[MAXN],maxid;
int a[MAXN],dp[MAXN];
int seg[MAXN << 2],tag[MAXN << 2];
priority_queue<int> Q[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void pushdown(int x,int l,int r) {
	if(tag[x]) {
		int mid = (l + r) >> 1;
		seg[x << 1] += tag[x];
		tag[x << 1] += tag[x];
		seg[x << 1 | 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		tag[x] = 0;
	}
}

void Update(int x,int l,int r,int L,int R,int v) {
	if(L > R) return;
	if(L <= l && r <= R) {
		seg[x] += v;
		tag[x] += v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(L <= mid) Update(x << 1,l,mid,L,R,v);
	if(R > mid) Update(x << 1 | 1,mid + 1,r,L,R,v);
	seg[x] = min(seg[x << 1],seg[x << 1 | 1]);
}

void Set(int x,int l,int r,int pos,int v) {
	if(l == r) {
		seg[x] = v;
		tag[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(pos <= mid) Set(x << 1,l,mid,pos,v);
	else Set(x << 1 | 1,mid + 1,r,pos,v);
	seg[x] = min(seg[x << 1],seg[x << 1 | 1]);
}

int Query(int x,int l,int r,int pos) {
	if(l == r) {
		if(seg[x] > 0) return INF;
		assert(!seg[x]);
		return l;
	}
	int mid = (l + r) >> 1;
	pushdown(x,l,r);
	if(pos > mid) return Query(x << 1 | 1,mid + 1,r,pos);
	if(seg[x << 1 | 1] == 0) return Query(x << 1 | 1,mid + 1,r,pos);
	return Query(x << 1,l,mid,pos);
}

int bit[MAXN];

void Add(int x,int v) {
	for(;x <= n;x += lowbit(x))
		bit[x] += v;
}

int Ask(int x) {
	int res = 0;
	for(;x;x -= lowbit(x)) res += bit[x];
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	memset(seg,0x3f,sizeof seg);
	for(int i = 1;i <= n; ++i) read(a[i]);
	for(int i = 1;i <= n; ++i) {
		dp[i] = dp[i - 1] + (a[i] <= i && dp[i - 1] + a[i] >= i);
	}
	for(int i = 1;i <= m; ++i) {
		read(q[i].x); read(q[i].y);
		q[i].id = i;
	}
	sort(q + 1,q + m + 1);
	int pre = n;
	for(int i = 1,x,y;i <= m; ++i) {
		x = q[i].x,y = q[i].y;
		for(int p = pre;p > x; --p) {
			Set(1,1,n,p,a[p] > p ? INF : p - a[p]);
			while(seg[1] == 0) {
				int pos = Query(1,1,n,p);
				Add(pos,1);
				Set(1,1,n,pos,INF);
				Update(1,1,n,pos + 1,n,-1);
			}
		}
		ans[q[i].id] = Ask(n - y);
		pre = x;
	}
	for(int i = 1;i <= m; ++i)
		cout << ans[i] << endl;
	return 0;
}