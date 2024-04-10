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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SAM {
	int len,fa;
	int ch[27];
	void clear() {
		len = fa = 0;
		for(int i = 0;i < 26; ++i) ch[i] = 0;
	}
} T[MAXN];

int TT,n,m,ans;
int endpos[MAXN];
int las = 1,tot = 1;
char s[MAXN];
vector<int> G[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void Insert(int x) {
	int np,p = las;
	np = las = ++tot;
	endpos[tot] = 1;
	T[np].len = T[p].len + 1;
	for(;p && !T[p].ch[x]; p = T[p].fa) T[p].ch[x] = np;
	if(!p) T[np].fa = 1;
	else {
		int q = T[p].ch[x];
		if(T[q].len == T[p].len + 1) T[np].fa = q;
		else {
			int nq = ++tot;
			T[nq] = T[q];
			T[nq].len = T[p].len + 1;
			T[q].fa = T[np].fa = nq;
			for(;p && T[p].ch[x] == q; p = T[p].fa) T[p].ch[x] = nq;
		}
	}
}

void DFS(int x) {
	for(auto to : G[x]) {
		DFS(to);
		endpos[x] += endpos[to];
	}
	ans += (T[x].len - T[T[x].fa].len) * (endpos[x] * endpos[x]);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(TT);
	while(TT--) {
		ans = 0;
		scanf("%s",s + 1);
		n = strlen(s + 1);
		for(int i = 1;i <= n; ++i) Insert(s[i] - 'a');
		for(int i = 2;i <= tot; ++i) G[T[i].fa].pb(i);
		DFS(1);
		printf("%lld\n",ans);
		for(int i = 1;i <= tot; ++i) {
			T[i].clear();
			G[i].clear();
			endpos[i] = 0;
		}
		las = tot = 1;
	}
	return 0;
}