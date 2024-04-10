//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int a[MAXN], k[MAXN];
set<pii> S;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void calc() {
	int sum = 0;
	for(int i = 1, lim; i + 2 <= n; ++i) {
		sum = a[i + 1];
		lim = (1ll << k[i]);
		for(int j = i + 2; j <= n; ++j) {
			if(sum >= lim) break;
			if((a[i] ^ a[j]) == sum) S.insert(mp(i, j));
			sum += a[j];
		}
	}
	for(int i = n, lim; i - 2 >= 1; --i) {
		sum = a[i - 1];
		lim = (1ll << k[i]);
		for(int j = i - 2; j >= 1; --j) {
			if(sum >= lim) break;
			if((a[i] ^ a[j]) == sum) S.insert(mp(j, i));
			sum += a[j];
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
		for(int p = 30; ~p; --p)
			if(a[i] & (1ll << p)) {
				k[i] = p + 1;
				break;
			}
	}
	calc();
	printf("%ld\n", S.size());
	return 0;
}