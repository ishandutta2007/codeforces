//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'
#define y1 _y1

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct Matrix {
	int a[3][3];
	void clear() { memset(a, 0x3f, sizeof a); }
	void unit() {
		clear();
		for(int i = 0; i <= 2; ++i) a[i][i] = 0;
	}
	Matrix operator * (const Matrix &b) const {
		Matrix res; res.clear();
		for(int i = 0; i <= 2; ++i)
			for(int j = 0; j <= 2; ++j)
				for(int k = 0; k <= 2; ++k)
					res.a[i][k] = min(res.a[i][k], a[i][j] + b.a[j][k]);
		return res;
	}
} sum[MAXN << 2], A, B, C;

int n, q, Ans;
char s[MAXN], t[5];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void build(int x, int l, int r) {
	if(l == r) {
		if(s[l] == 'a') sum[x] = A;
		if(s[l] == 'b') sum[x] = B;
		if(s[l] == 'c') sum[x] = C;
		return;
	}
	int mid = (l + r) >> 1;
	build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	sum[x] = sum[x << 1] * sum[x << 1 | 1];
}

void update(int x, int l, int r, int p, char c) {
	if(l == r) {
		s[l] = c;
		if(s[l] == 'a') sum[x] = A;
		if(s[l] == 'b') sum[x] = B;
		if(s[l] == 'c') sum[x] = C;
		return;
	}
	int mid = (l + r) >> 1;
	if(p <= mid) update(x << 1, l, mid, p, c);
	else update(x << 1 | 1, mid + 1, r, p, c);
	sum[x] = sum[x << 1] * sum[x << 1 | 1];
}

void print() {
	Ans = INF;
	Ans = min(Ans, sum[1].a[0][0]);
	Ans = min(Ans, sum[1].a[0][1]);
	Ans = min(Ans, sum[1].a[0][2]);
	printf("%lld\n", Ans);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	A.clear(), B.clear(), C.clear();
	A.a[0][0] = 1, A.a[0][1] = 0, A.a[1][1] = 0, A.a[2][2] = 0;
	B.a[0][0] = 0, B.a[1][1] = 1, B.a[1][2] = 0, B.a[2][2] = 0;
	C.a[0][0] = 0, C.a[1][1] = 0, C.a[2][2] = 1;
	read(n), read(q);
	scanf("%s", s + 1);
	build(1, 1, n);
	while(q--) {
		int p; read(p), scanf("%s", t + 1);
		update(1, 1, n, p, t[1]); 
		print();
	}
	return 0;
}