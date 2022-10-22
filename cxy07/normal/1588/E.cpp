//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 3010;
const int INF = 2e9;
const double eps = 1e-8;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
double X[MAXN], Y[MAXN], _R, ang[MAXN], l[MAXN], r[MAXN];
bool ok[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

double dis(int x, int y) {
	return sqrt((X[x] - X[y]) * (X[x] - X[y]) + (Y[x] - Y[y]) * (Y[x] - Y[y]));
}

void calc(int st) {
	double L = -INF, R = INF;
	bool flag = false;
	for(int i = 1; i <= n; ++i) {
		if(i == st) continue;
		ang[i] = atan2(Y[i] - Y[st], X[i] - X[st]);
		if(dis(i, st) < _R + eps) continue;
		double dt = asin(_R / dis(i, st));
		l[i] = ang[i] - dt, r[i] = ang[i] + dt;
		if(!flag) L = l[i], R = r[i], flag = true;
		else {
			if(l[i] > R + eps) l[i] -= 2 * PI, r[i] -= 2 * PI;
			if(r[i] < L - eps) l[i] += 2 * PI, r[i] += 2 * PI;
			L = max(L, l[i]), R = min(R, r[i]);
		}
		if(L > R + eps) break;
	}
	for(int i = 1; i <= n; ++i) {
		if(i == st) continue;
		double cur = ang[i];
		if(cur > R + eps) cur -= 2 * PI;
		if(cur < L - eps) cur += 2 * PI;
		if(L - eps < cur && cur < R + eps) ok[st][i] = true;
	}
}

signed main () {
#ifdef FILE
	freopen("CF1588E.in", "r", stdin);
	freopen("CF1588E.out", "w", stdout);
#endif
	read(n); scanf("%lf", &_R);
	for(int i = 1; i <= n; ++i) scanf("%lf%lf", &X[i], &Y[i]);
	for(int i = 1; i <= n; ++i) calc(i);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(ok[i][j] && ok[j][i]) ++Ans;
	printf("%d\n", Ans);
	return 0;
}