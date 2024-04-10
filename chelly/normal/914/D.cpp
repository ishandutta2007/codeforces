#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 500033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
LL bt[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int g[N * 4];
int a[N];
int n;
void inc(int posi, int delta) {
	for(int i(posi); i <= n; i += i & -i) {
		bt[i] += delta;
	}
}
LL getSum(int posi) {
	LL res = 0;
	for(int i(posi); i; i -= i & -i)
		res += bt[i];
	return res;
}
void init(int k, int le, int ri) {
	if(le == ri) {
		g[k] = a[le];
	}else {
		int mid(le + ri >> 1);
		init(k * 2, le, mid);
		init(k * 2 + 1, mid + 1, ri);
		g[k] = gcd(g[k * 2], g[k * 2 + 1]);
	}
}
int getGCD(int k, int le, int ri, int ql, int qr) {
	if(ql <= le && ri <= qr) {
		return g[k];
	}else {
		int mid(le + ri >> 1);
		int res = 0;
		if(ql <= mid) res = gcd(getGCD(k * 2, le, mid, ql, qr), res);
		if(qr > mid) res = gcd(getGCD(k * 2 + 1, mid + 1, ri, ql, qr), res);
		return res;
	}
}
void update(int k, int le, int ri, int posi, int val) {
	if(le == ri) {
		g[k] = val;
	}else {
		int mid(le + ri >> 1);
		if(posi <= mid) update(k * 2, le, mid, posi, val);
		else update(k * 2 + 1, mid + 1, ri, posi, val);
		g[k] = gcd(g[k * 2], g[k * 2 + 1]);
	}
}
int f1(int k, int le, int ri, int x) {
	if(le == ri) {
		return le;
	}else {
		int mid(le + ri >> 1);
		if(g[k * 2] % x) return f1(k * 2, le, mid, x);
		return f1(k * 2 + 1, mid + 1, ri, x);
	}
}
int find(int k, int le, int ri, int ql, int qr, int x) {
	if(ql <= le && ri <= qr) {
		if(g[k] % x == 0) return 0;
		return f1(k, le, ri, x);
	}else {
		int mid(le + ri >> 1);
		int res = ql <= mid ? find(k * 2, le, mid, ql, qr, x) : 0;
		if(res) return res;
		else return find(k * 2 + 1, mid + 1, ri, ql, qr, x);
	}
}
int main() {
	n = getInt();
	for(int i(1); i <= n; i++) a[i] = getInt();
	init(1, 1, n);
	for(int i(1); i <= n; i++) inc(i, a[i]);
	int Q;
	Q = getInt();
	for(int i(1); i <= Q; i++) {
		int tp;
		//printf("%d\n",i);
		tp = getInt();
		if(tp == 1) {
			int l, r, x;
			l = getInt(); r = getInt(); x = getInt();
//if(l > n) l = n; if(r > n) r = n;
//if(l > r) swap(l, r);
			int t = getGCD(1, 1, n, l, r);
			//printf("t = %d\n", t);
			bool ans;
			if(t % x == 0) {
				ans = true;
			}else {
				LL s = getSum(r) - getSum(l - 1);
				if(s % x == 0) {
					ans = false;
				}else {
				//	printf("A %d %I64d %d\n", x, s, t);
					int posi = find(1, 1, n, l, r, x) - 1;
				//	printf("A\n");

					ans = (l > posi || getGCD(1, 1, n, l, posi) % x == 0) && (posi + 2 > r || getGCD(1, 1, n, posi + 2, r) % x == 0);
				}
			}
			printf("%s\n", ans ? "YES" : "NO");
		}else {
			int l, x;
			l = getInt(); x = getInt();
//if(l > n) l = n;
			update(1, 1, n, l, x);
			inc(l, -a[l]);
			a[l] = x;
			inc(l, a[l]);
		}
	}
}