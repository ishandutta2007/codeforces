//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcountll(x)
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

const int MAXN = 45;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, p2[MAXN], a[MAXN];
int pos[MAXN], pre[MAXN], occ[MAXN];
int make[MAXN][MAXN];
bool flag = true;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool ok(int S) { return S == (p2[n + 1] - lowbit(S | p2[n + 1])); }

void print(int S) {
	for(int i = 1; i <= n; ++i) cout << ((S >> i) & 1) << ' ';
	cout << endl;
}

void DFS(int x, int S) {
	if(x > k) return flag &= ok(S), void();
	int c = popc(occ[x]), o = popc(S & pos[x]);
	for(int i = 0; i <= c; ++i) {
		DFS(x + 1, (S & (~pos[x])) | make[x][i + o]);
		if(!flag) puts("REJECTED"), exit(0);
	}
}

signed main () {
#ifdef FILE
	freopen("CF1552G.in", "r", stdin);
	freopen("CF1552G.out", "w", stdout);
#endif
	read(n), read(k); p2[0] = 1;
	if(n == 1) return puts("ACCEPTED"), 0;
	for(int i = 1; i < MAXN; ++i) p2[i] = p2[i - 1] << 1;
	for(int i = 1, x; i <= k; ++i) {
		read(x), make[i][0] = 0;
		for(int j = 1; j <= x; ++j) 
			read(a[j]), pos[i] |= p2[a[j]];
		for(int j = 1; j <= x; ++j)
			make[i][j] = make[i][j - 1] | p2[a[x - j + 1]];
		pre[i] = pre[i - 1] | pos[i];
		occ[i] = pre[i - 1] ^ pre[i];
	}
	if(popc(pre[k]) != n) return puts("REJECTED"), 0;
	DFS(1, 0);
	puts(flag ? "ACCEPTED" : "REJECTED");
	return 0;
}