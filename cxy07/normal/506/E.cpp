//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
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

const int MAXN = 310;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e4 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt, ans;
int G[MAXN][MAXN], h[MAXN][MAXN][MAXN], Ans[MAXN];
int tmp1[MAXN][MAXN], tmp2[MAXN], tmp3[MAXN][MAXN], tmp4[MAXN];
bool ok[MAXN][MAXN][MAXN];
char s[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void Modadd(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

int v(int x) {return (x >> 1) + (x & 1);}

int H(int i, int l, int r) {
	if(i < 0) return 0;
	if(ok[i][l][r]) return h[i][l][r];
	ok[i][l][r] = true;
	if(l == 1 && r == m) return h[i][l][r] = (!i);
	if(l > 1 && s[l - 1] != s[r]) Modadd(h[i][l][r], H(i - 1, l - 1, r));
	if(r < m && s[r + 1] != s[l]) Modadd(h[i][l][r], H(i - 1, l, r + 1));
	if(l > 1 && r < m && s[l - 1] == s[r + 1])
		Modadd(h[i][l][r], H(i, l - 1, r + 1));
	return h[i][l][r];
}

void mul(int opt) {
	if(!opt) {
		for(int i = 1; i <= cnt; ++i)
			for(int j = i; j <= cnt; ++j)
				for(int k = j; k <= cnt; ++k)
					Modadd(tmp3[i][k], G[i][j] * G[j][k] % mod);
		for(int i = 1; i <= cnt; ++i)
			for(int j = 1; j <= cnt; ++j)
				G[i][j] = tmp3[i][j], tmp3[i][j] = 0;
	} else {
		for(int i = 1; i <= cnt; ++i)
			for(int j = 1; j <= cnt; ++j)
				Modadd(tmp4[j], Ans[i] * G[i][j] % mod);
		for(int i = 1; i <= cnt; ++i) Ans[i] = tmp4[i], tmp4[i] = 0;
	}
}

void qpow(int lim) {
	for(; lim; lim >>= 1, mul(0)) 
		if(lim & 1) mul(1);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	scanf("%s", s + 1);
	read(n), m = strlen(s + 1); cnt = m + v(m);
	for(int i = 0, tot; i < m; ++i) {
		tot = 0;
		for(int j = 1; j <= m; ++j) {
			Modadd(tot, H(i, j, j));
			if((j ^ m) && s[j] == s[j + 1]) Modadd(tot, H(i, j, j + 1));
		}
		if(!i) {
			Ans[m] = tot, G[cnt][cnt] = 26;
			for(int j = m; j < cnt; ++j) G[j][j + 1] = 1, G[j][j] = 25;
			continue;
		}
		G[i][cnt - v(m - i)] = tot, G[i][i] = 24;
		if(i ^ 1) G[i - 1][i] = 1;
	}
	Ans[1] = 1;
	memcpy(tmp1, G, sizeof tmp1), memcpy(tmp2, Ans, sizeof tmp2);
	qpow(v(n + m));
	if(((n + m) & 1) == 0) return printf("%d\n", Ans[cnt]), 0;
	ans = Ans[cnt];
	memcpy(G, tmp1, sizeof tmp1), memcpy(Ans, tmp2, sizeof tmp2);
	for(int i = 0, tot; i < m; ++i) {
		tot = 0;
		for(int j = 1; j < m; ++j)
			if(s[j] == s[j + 1]) Modadd(tot, H(i, j, j + 1));
		if(i) G[i][cnt - v(m - i)] = tot;
		else Ans[m] = tot, G[cnt][cnt] = 0;
	}
	qpow(v(n + m));
	Modadd(ans, mod - Ans[cnt]);
	printf("%d\n", ans);
	return 0;
}