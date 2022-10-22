//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) ksm(x,mod - 2)
#define lowbit(x) (x & (-x))

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;

struct NODE {
	int x,y;
	bool operator < (const NODE &b) const {return x < b.x;}
} node[MAXN];

int n,ans,a[MAXN];
int seg[MAXN << 2],sum[MAXN << 2],tag[MAXN << 2];
int mx[MAXN],mn[MAXN],p1,p2;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void pushup(int x) {
	if(seg[x << 1] < seg[x << 1 | 1]) {
		seg[x] = seg[x << 1];
		sum[x] = sum[x << 1];
	} else if(seg[x << 1 | 1] < seg[x << 1]) {
		seg[x] = seg[x << 1 | 1];
		sum[x] = sum[x << 1 | 1];
	} else {
		assert(seg[x << 1] == seg[x << 1 | 1]);
		seg[x] = seg[x << 1];
		sum[x] = sum[x << 1] + sum[x << 1 | 1];
	}
}

void pushdown(int x) {
	if(!tag[x]) return;
	seg[x << 1] += tag[x];
	seg[x << 1 | 1] += tag[x];
	tag[x << 1] += tag[x];
	tag[x << 1 | 1] += tag[x];
	tag[x] = 0;
}

void update(int x,int l,int r,int L,int R,int val) {
	if(L > R) return;
	if(L <= l && r <= R) {
		seg[x] += val;
		tag[x] += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x);
	if(L <= mid) update(x << 1,l,mid,L,R,val);
	if(R > mid) update(x << 1 | 1,mid + 1,r,L,R,val);
	pushup(x);
}

void insert(int x,int l,int r,int pos,int val) {
	if(l == r) {
		seg[x] = val;
		sum[x] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(x);
	if(pos <= mid) insert(x << 1,l,mid,pos,val);
	else insert(x << 1 | 1,mid + 1,r,pos,val);
	pushup(x);
}

int query(int x,int l,int r,int L,int R) {
	if(L <= l && r <= R) {
		if(seg[x]) return 0;
		return sum[x];
	}
	int mid = (l + r) >> 1,res = 0;
	pushdown(x);
	if(L <= mid) res += query(x << 1,l,mid,L,R);
	if(R > mid) res += query(x << 1 | 1,mid + 1,r,L,R);
	return res;
}

void build(int x,int l,int r) {
	if(l == r) {
		seg[x] = INF;
		sum[x] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1,l,mid);
	build(x << 1 | 1,mid + 1,r);
	pushup(x);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1;i <= n; ++i) {
		read(node[i].x);
		read(node[i].y);
	}
	//for(int i = 1;i <= n; ++i) read(node[i].y);
	sort(node + 1,node + n + 1);
	for(int i = 1;i <= n; ++i) a[i] = node[i].y;
	build(1,1,n);
	for(int i = 1;i <= n; ++i) {
		int lim = i;
		insert(1,1,n,i,0);
		update(1,1,n,1,i - 1,-1);
		int pre = i;
		while(p1 && a[mx[p1]] < a[i]) {
			update(1,1,n,mx[p1 - 1] + 1,mx[p1],a[i] - a[mx[p1]]);
			p1--;
		}
		mx[++p1] = i;
		while(p2 && a[mn[p2]] > a[i]) {
			update(1,1,n,mn[p2 - 1] + 1,mn[p2],a[mn[p2]] - a[i]);
			p2--;
		}
		mn[++p2] = i;
		ans += query(1,1,n,1,i);
	}
	printf("%lld\n",ans);
	return 0;
}