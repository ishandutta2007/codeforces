//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int k, l, d[MAXN];
bool safe[MAXN], flag;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

bool chk(int x, int y) {
	for(int st = 0; st <= k; ++st) {
		int now = st, opt = 1;
		bool ok = true;
		for(int i = x + 1; i <= y; ++i) {
			if(d[i] + now > l) {
				ok = false;
				break;
			}
			if(now == 0) opt = 1;
			else if(now == k) opt = -1;
			now += opt;
			assert(0 <= now && now <= k);
		}
		if(ok) return true;
	}
	for(int st = 0; st <= k; ++st) {
		int now = st, opt = -1;
		bool ok = true;
		for(int i = x + 1; i <= y; ++i) {
			if(d[i] + now > l) {
				ok = false;
				break;
			}
			if(now == 0) opt = 1;
			else if(now == k) opt = -1;
			now += opt;
			assert(0 <= now && now <= k);
		}
		if(ok) return true;	
	}
	return false;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); read(k); read(l);
		flag = true;
		for(int i = 1; i <= n; ++i) {
			read(d[i]);
			safe[i] = (bool)(d[i] + k <= l);
		}
		safe[0] = safe[n + 1] = true;
		d[0] = d[n + 1] = -INF;
		int pre = 0;
		for(int i = 1; i <= n; ++i) {
			if(safe[i]) {
				if(!chk(pre, i)) {
					flag = false;
					break;
				}
				pre = i;
			}
		}
		if(!chk(pre, n + 1)) flag = false;
		puts(flag ? "Yes" : "No");
	}
	return 0;
}