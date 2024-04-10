//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
char s[MAXN], t[MAXN];
vec<int> ans;

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); ans.clear();
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		for(int i = n; i >= 1; --i) {
			if(s[i] != t[i]) {
				if(s[1] == t[i]) {
					ans.pb(1);
					s[1] = (s[1] == '1' ? '0' : '1');
				}
				ans.pb(i);
				for(int p = 1; p <= i; ++p) s[p] = (s[p] == '0' ? '1' : '0');
				for(int p = 1; p <= i / 2; ++p) swap(s[p], s[i - p + 1]);
			}
		}
		/*for(int i = 1; i <= n; ++i)
			assert(s[i] == t[i]);*/
		cout << ans.size() << ' ';
		for(auto v : ans) cout << v << ' ';
		cout << endl;
	}
	return 0;
}