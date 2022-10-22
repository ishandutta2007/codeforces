//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 210;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, b;
char s[5];
bool res;
vec<int> now;
string ans, opt;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void print(int pos, string now, int op) {
	res = 0;
	cout << pos << ' ' << ans << now;
	for(int i = ans.length() + now.size(); i < b; ++i) putchar(op + '0');
	cout << endl;
	cin >> opt; res = (opt[0] == 'y');
}

void solve(vec<int> id) {
	if(ans.size() == b) return;
	if(!id.size()) {
		int lim = ans.size();
		for(int i = lim + 1; i <= b; ++i) ans = ans + "0";
		return;
	}
	string cur = ""; vec<int> stk(0);
	print(id[0], "0", 1);
	cur += (res ? "1" : "0");
	stk.pb(id[0]);
	for(int i = 1, p, ok; i < id.size(); ++i) {
		p = id[i], ok = false;
		print(p, cur, 1);
		if(res) ok = true;
		while(stk.size() && res) {
			cur.pop_back();
			stk.pop_back();
			print(p, cur, 1);
		}//>
		if(ans.size() + cur.size() == b) continue;
		res = false;
		if(!ok) print(p, cur + "0", 1);
		if(ok || res) cur += "1";
		else cur += "0";
		stk.pb(p);
	}
	for(int i = stk.size() - 1; ~i; --i) {
		print(stk[i], cur, 1);
		if(res) {
			while(stk.size() > i + 1) {
				stk.pop_back();
				cur.pop_back();
			}
		}
	}
	ans += cur; 
	solve(stk);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n), read(b);
	for(int i = 1; i <= n; ++i) now.pb(i);
	solve(now);
	cout << 0 << ' ' << ans << endl;
	return 0;
}