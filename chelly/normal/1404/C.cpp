#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
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

inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
struct P {
	D x, y;
};
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], ans[N];
vector<pair<int, int > > q[N];
struct SGT {
	int mn, mni, delta;
} sgt[N * 4];
int bt[N];
void add(int x) {
	for(int p = x; p <= n; p += p & -p) bt[p] += 1;
}
int getsum(int x) {
	int res = 0;
	for(int p = x; p; p -= p & -p) res += bt[p];
	return res;
}
void build(int k, int le, int ri) {
	sgt[k].mn = inf; 
	sgt[k].mni = le;
	sgt[k].delta = 0;
	if(le != ri) {
		int mid = (le + ri) / 2;
		build(k * 2, le, mid);
		build(k * 2 + 1, mid + 1, ri);
	}
}
void pushdown(int k) {
	int d = sgt[k].delta;
	sgt[k * 2].delta += d;
	sgt[k * 2].mn += d;
	sgt[k * 2 + 1].delta += d;
	sgt[k * 2 + 1].mn += d;
	sgt[k].delta = 0;
}
void collect(int k) {
	if(sgt[k * 2].mn <= sgt[k * 2 + 1].mn) {
		sgt[k].mn = sgt[k * 2].mn;
		sgt[k].mni = sgt[k * 2].mni;
	}else {
		sgt[k].mn = sgt[k * 2 + 1].mn;
		sgt[k].mni = sgt[k * 2 + 1].mni;
	}
}
void modify(int k, int le, int ri, int pos) {
	if(le == ri) {
		sgt[k].mn = a[pos];
	}else {
		pushdown(k);
		int mid = (le + ri) / 2;
		if(pos <= mid) modify(k * 2, le, mid, pos);
		else modify(k * 2 + 1, mid + 1, ri, pos);
		collect(k);
	}
}
void sub(int k, int le, int ri, int pos) {
	if(le >= pos) {
		sgt[k].mn--;
		sgt[k].delta --;
	}else {
		pushdown(k);
		int mid = (le + ri) / 2;
		if(pos <= mid) sub(k * 2, le, mid, pos);
		sub(k * 2 + 1, mid + 1, ri, pos);
		collect(k);
	}
}
int main() {
	int Q;
	scanf("%d%d", &n, &Q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(a[i] <= i) {
			a[i] = i - a[i];
		}else a[i] = inf;
	}
	build(1, 1, n);
	for(int i = 1; i <= Q; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		q[x].pb({n - y, i});
	}
	for(int i = n - 1; i >= 0; i--) {
		if(a[i + 1] == 0) {
			add(i + 1);
			a[i + 1] = inf;
			modify(1, 1, n, i + 1);
			sub(1, 1, n, i + 1);
			while(sgt[1].mn <= 0) {
				int id = sgt[1].mni;
				a[id] = inf;
				modify(1, 1, n, id);
				sub(1, 1, n, id);
				add(id);
			}
		}else {
			modify(1, 1, n, i + 1);
		}
		for(auto tmp : q[i]) {
			int y = tmp.fi;
			ans[tmp.se] = getsum(y);
		}
	}
	for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
}