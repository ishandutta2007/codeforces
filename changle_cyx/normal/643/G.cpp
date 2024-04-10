#include <bits/stdc++.h>

#define lcc x << 1, l, mid
#define rcc x << 1 | 1, mid + 1, r

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar()));
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

int p; 
struct node {
	int cnt, a[5], b[5]; 
	
	inline void init() {
		cnt = 0; 
		memset(a, 0, sizeof(a)); 
		memset(b, 0, sizeof(b)); 
	}
	inline void setSame(int v, int len) {
		cnt = 1, a[0] = v, b[0] = len; 
	}

	inline node operator + (const node &rhs) const {
		node res = rhs; 
		for (int i = 0; i < cnt; ++i) {
			bool flg = false; 
			for (int j = 0; j < res.cnt; ++j)
				if (res.a[j] == a[i]) {
					flg = true; 
					res.b[j] += b[i]; 
					break; 
				}
			
			if (flg) continue; 

			if (res.cnt < p) {
				res.a[res.cnt] = a[i]; 
				res.b[res.cnt] = b[i]; 
				++res.cnt; 
			} else {
				int minPos = 0; 
				for (int j = 1; j < res.cnt; ++j)
					if (res.b[minPos] > res.b[j]) {
						minPos = j; 
					}
				
				if (b[i] < res.b[minPos]) {
					for (int j = 0; j < res.cnt; ++j)
						res.b[j] -= b[i]; 
				} else {
					int tmp = res.b[minPos]; 
					res.a[minPos] = a[i]; 
					res.b[minPos] = b[i]; 
					for (int j = 0; j < res.cnt; ++j)
						res.b[j] -= tmp; 
				}
			}
		}
		return res; 
	}
}; 

const int MaxN = 1.5e5 + 5; 
const int MaxS = MaxN << 2; 

int n, m; 
int a[MaxN]; 

node seg[MaxS]; 
int tag[MaxS], len[MaxS]; 

inline void upt(int x) {
	seg[x] = seg[x << 1] + seg[x << 1 | 1]; 
}

inline void nodeModify(int x, int v) {
	tag[x] = v; 
	seg[x].setSame(v, len[x]); 
}

inline void dnt(int x) {
	if (tag[x]) {
		nodeModify(x << 1 | 0, tag[x]); 
		nodeModify(x << 1 | 1, tag[x]); 
		tag[x] = 0; 
	}
}

inline void segBuild(int x = 1, int l = 1, int r = n) {
	len[x] = r - l + 1; 

	if (l == r) {
		read(seg[x].a[0]); 
		seg[x].b[0] = seg[x].cnt = 1; 

		return; 
	}
	int mid = (l + r) >> 1; 
	segBuild(lcc), segBuild(rcc), upt(x); 
}

inline void segModify(int u, int v, int val, int x = 1, int l = 1, int r = n) {
	if (u <= l && r <= v) {
		nodeModify(x, val); 
		return; 
	}
	dnt(x); 
	int mid = (l + r) >> 1; 
	if (u <= mid)
		segModify(u, v, val, lcc); 
	if (v > mid)
		segModify(u, v, val, rcc);  
	upt(x); 
}

inline node segQuery(int u, int v, int x = 1, int l = 1, int r = n) {
	if (u <= l && r <= v) {
		return seg[x]; 
	}
	dnt(x); 
	
	node res; res.init(); 
	int mid = (l + r) >> 1; 
	if (u <= mid)
		res = res + segQuery(u, v, lcc); 
	if (v > mid)
		res = res + segQuery(u, v, rcc); 
	return res; 
}

int main() {
#ifdef orzczk
	freopen("ads.in", "r", stdin); 
#endif

	read(n), read(m), read(p), p = 100 / p; 
	segBuild(); 

	while (m--) {
		int opt, l, r, x; 
		
		read(opt), read(l), read(r); 
		if (opt == 1) {
			read(x); 
			segModify(l, r, x); 
		} else {
			node res = segQuery(l, r); 
			printf("%d ", res.cnt); 
			for (int i = 0; i < res.cnt; ++i) {
				printf("%d%c", res.a[i], " \n"[i == res.cnt - 1]); 
			}
		}
	}

	return 0; 
}