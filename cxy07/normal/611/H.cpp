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

const int MAXN = 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int sum[MAXN], cnt[MAXN][MAXN], id[MAXN];
char sa[MAXN], sb[MAXN];
bool vis[MAXN];
vec<pii> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

bool chk() {
	for(int S = 1, X, to; S < (1 << m) - 1; ++S) {
		X = to = 0;
		for(int i = 1; i <= m; ++i)
			if((S >> (i - 1)) & 1) X += sum[i];
		for(int i = 1; i <= m; ++i)
			for(int j = i; j <= m; ++j)
				if(((S >> (i - 1)) & 1) || ((S >> (j - 1)) & 1)) to += cnt[i][j];
		if(X > to) return false;
	}
	return true;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); int tmp = n;
	while(tmp) m++, tmp /= 10;
	for(int i = 1, a, b; i < n; ++i) {
		scanf("%s%s", sa + 1, sb + 1);
		a = strlen(sa + 1), b = strlen(sb + 1);
		cnt[a][b]++;
		if(a ^ b) cnt[b][a]++;
	}
	sum[0] = id[1] = 1;
	for(int i = 2; i <= m; ++i) id[i] = id[i - 1] * 10;
	for(int i = 1; i <= m; ++i) id[i]--;
	for(int i = 1; i <= m; ++i) sum[i] = sum[i - 1] * 10;
	sum[m] = n + 1;
	for(int i = m; i >= 1; --i) sum[i] = sum[i] - sum[i - 1];
	if(!chk()) return puts("-1"), 0;
	id[1]++, sum[1]--, vis[1] = true;
	while(Ans.size() < n - 1) {
		for(int i = 1; i <= m; ++i) {
			if(!vis[i]) continue;
			for(int j = 1; j <= m; ++j) {
				if(!cnt[i][j] || !sum[j]) continue;
				cnt[i][j]--, sum[j]--;
				if(i ^ j) cnt[j][i]--;
				if(chk()) {
					Ans.pb(mp(id[i], id[j] + 1));
					vis[j] = true, id[j]++;
				} else {
					cnt[i][j]++, sum[j]++;
					if(i ^ j) cnt[j][i]++;
				}
			}
		}
	}
	for(auto x : Ans) printf("%d %d\n", x.fst, x.scd);
	return 0;
}