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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const int G = 3;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;

int n,m;
int a[MAXN];
int mx[MAXN << 2],sum[MAXN << 2];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void pushup(int x) {
	mx[x] = max(mx[x << 1],mx[x << 1 | 1]);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

void build(int root,int l,int r) {
	if(l == r) {
		mx[root] = sum[root] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	pushup(root);
}

void update(int root,int l,int r,int pos,int val) {
	if(l == r) {
		mx[root] = sum[root] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) update(root << 1,l,mid,pos,val);
	else update(root << 1 | 1,mid + 1,r,pos,val);
	pushup(root);
}

int query(int root,int l,int r,int L,int R) {
	if(L <= l && r <= R) return sum[root];
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid) res += query(root << 1,l,mid,L,R);
	if(R > mid) res += query(root << 1 | 1,mid + 1,r,L,R);
	return res;
}

void Mod(int root,int l,int r,int L,int R,int p) {
	if(mx[root] < p) return;
	if(l == r) {
		mx[root] %= p;
		sum[root] %= p;
		return;
	}
	int mid = (l + r) >> 1;
	if(L <= mid) Mod(root << 1,l,mid,L,R,p);
	if(R > mid) Mod(root << 1 | 1,mid + 1,r,L,R,p);
	pushup(root);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n); read(m);
	for(int i = 1;i <= n; ++i) read(a[i]);
	build(1,1,n);
	while(m--) {
		int opt,l,r,v;
		read(opt); read(l); read(r);
		if(opt == 2) read(v);
		if(opt == 1) printf("%lld\n",query(1,1,n,l,r));
		else if(opt == 2) Mod(1,1,n,l,r,v);
		else update(1,1,n,l,r);
	}
	return 0;
}