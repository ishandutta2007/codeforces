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
int ans = 0, Min, fa[MAXN];
char s[MAXN], t[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

int find(int x) {
	if(fa[x] == x) return fa[x];
	return fa[x] = find(fa[x]);
}

void unity(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	ans++;
	fa[y] = x;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) {
		read(n); ans = 0;
		Min = INF;
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		for(int i = 0; i <= 26; ++i) fa[i] = i;
		for(int i = 1; i <= n; ++i) {
			if(s[i] > t[i]) {
				ans = -1;
				break;
			} else unity(s[i] - 'a' + 1, t[i] - 'a' + 1);
		}
		cout << ans << endl;
	}
	return 0;
}