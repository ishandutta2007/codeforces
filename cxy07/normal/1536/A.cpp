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

const int MAXN = 110;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a[MAXN];
set<int> S;
queue<int> Q;
vec<int> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) {
		read(n); Ans.clear(), S.clear();
		while(Q.size()) Q.pop();
		for(int i = 1; i <= n; ++i) {
			read(a[i]);
			Ans.pb(a[i]), S.insert(a[i]);
		}
		for(int i = 1; i <= n; ++i)
			for(int j = i + 1; j <= n; ++j)
				if(!S.count(abs(a[i] - a[j]))) Q.push(abs(a[i] - a[j]));
		while(Q.size() && Ans.size() <= 500) {
			int x = Q.front(); Q.pop();
			if(S.count(x)) continue;
			S.insert(x);
			for(auto v : Ans) if(!S.count(abs(v - x))) Q.push(abs(v - x));
			Ans.pb(x);
		}
		if(Ans.size() > 500) puts("NO");
		else {
			puts("YES");
			printf("%ld\n", Ans.size());
			for(auto x : Ans) printf("%d ", x);
			putchar('\n');
		}
	}
	return 0;
}