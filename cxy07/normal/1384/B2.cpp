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
	if(y == x + 1) return true;
	int p, opt = -1;
	p = l - d[x + 1];
	//cout << p << endl;
	assert(0 <= p && p <= k);
	for(int i = x + 1; i <= y; ++i) {
		if(d[i] + p > l) {
			if(opt == 1) return false;
			else p = l - d[i];
		}
		if(!p) opt = 1;
		else if(p == k) opt = -1;
		p += opt;
	}
	return true;
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
			if(d[i] > l) flag = false;
			safe[i] = (bool)(d[i] + k <= l);
		}
		if(!flag) {
			puts("No");
			continue;
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