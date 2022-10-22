//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const int mod = 1e9 + 7;

int n,lim,ans = -1,sav;
int a[MAXN],x,sum[MAXN];
int seg[MAXN << 2],tag[MAXN << 2];

inline void pushup(int x) {seg[x] = min(seg[x << 1],seg[x << 1 | 1]);}

inline void pushdown(int x,int l,int r) {
	if(tag[x]) {
		int mid = (l + r) >> 1;
		tag[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		seg[x << 1] += tag[x];
		seg[x << 1 | 1] += tag[x];
		tag[x] = 0;
	}
}

void build(int root,int l,int r) {
	if(l == r) {
		seg[root] = sum[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	pushup(root);
}

void update(int root,int l,int r,int L,int R,int val) {
	if(L <= l && r <= R) {
		seg[root] += val;
		tag[root] += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(root,l,r);
	if(L <= mid) update(root << 1,l,mid,L,R,val);
	if(R > mid) update(root << 1 | 1,mid + 1,r,L,R,val);
	pushup(root);
}

int query(int root,int l,int r,int L,int R) {
	if(L <= l && r <= R) return seg[root];
	int mid = (l + r) >> 1,res = 0;
	pushdown(root,l,r);
	if(L <= mid) res += query(root << 1,l,mid,L,R);
	if(R > mid) res += query(root << 1 | 1,mid + 1,r,L,R);
	return res;
}


signed main () {
	cin >> n;
	lim = ceil(n / 2.0);
	for(register int i = 1;i <= lim; ++i)
		cin >> a[i],sum[1] += a[i];
	cin >> x;
	sum[1] += n / 2 * x;
	for(register int i = 2;i <= lim; ++i)
		sum[i] = sum[i - 1] + x - a[i - 1];
	build(1,1,lim);
	sav = sum[1];
	for(register int i = 1;i <= lim; ++i) {
		sav = min(sav,sum[i]);
		if(sav > x * (i - 1)) return (printf("%lld\n",n - i + 1)),0;
	} 
	cout << -1 << endl;
	return 0;
}