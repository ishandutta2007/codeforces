#include <bits/stdc++.h>

using namespace std; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

namespace segt {
	#define lcc x << 1, l, mid
	#define rcc x << 1 | 1, mid + 1, r

	const int MaxS = 800000 + 5; 

	struct node {
		int pre, suf, sum;
		node operator + (const node &rhs) const {
			node res; 
			res.pre = max(pre, sum + rhs.pre); 
			res.suf = max(suf + rhs.sum, rhs.suf); 
			res.sum = sum + rhs.sum; 
			return res; 
		}
	}seg[MaxS]; 

	int n; 
	int leaf[MaxS]; 

	void upt(int x) {
		seg[x] = seg[x << 1] + seg[x << 1 | 1]; 
	}

	void build(int x = 1, int l = 1, int r = n) {
		if (l == r) return (void)(seg[leaf[l] = x] = {1, 1, 1}); 
		
		int mid = (l + r) >> 1; 
		build(lcc), build(rcc), upt(x); 
	}

	void rev(int p) {
		int x = leaf[p]; 
		seg[x] = {0, 0, -1}; 
		for (x >>= 1; x; x >>= 1) upt(x); 
	}
	
	node query(int u, int v, int x = 1, int l = 1, int r = n) {
		if (u > v) return {0, 0, 0}; 
		if (u <= l && r <= v) return seg[x]; 

		int mid = (l + r) >> 1; 
		if (v <= mid) return query(u, v, lcc); 
		else if (u > mid) return query(u, v, rcc); 
		else return query(u, mid, lcc) + query(mid + 1, v, rcc); 
	}
}

const int MaxN = 200000 + 5; 

int n; 
int a[MaxN]; 
vector<int> p[MaxN]; 

int ans1[MaxN], ans2[MaxN]; 

int main() {
	read(n); 
	for (int i = 1; i <= n; ++i) read(a[i]), p[a[i]].push_back(i); 

	segt::n = n; 
	segt::build(); 
	
	for (int v = 1; v <= n; ++v) {
		for (int i : p[v]) ans1[i] = segt::query(1, i - 1).suf + segt::query(i + 1, n).pre; 
		for (int i : p[v]) segt::rev(i); 
	}

	segt::build(); 
	for (int v = n; v >= 1; --v) {	
		for (int i : p[v]) ans2[i] = segt::query(1, i - 1).suf + segt::query(i + 1, n).pre; 
		for (int i : p[v]) segt::rev(i); 
	}

	for (int i = 1; i <= n; ++i) {
		printf("%d%c", max((ans1[i] + 3) / 2 - 1, ans2[i] + 1 - (ans2[i] + 3) / 2), " \n"[i == n]); 
	}

	return 0; 
}