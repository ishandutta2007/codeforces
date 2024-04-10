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

const int MAXN = 1e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, k;
int x[MAXN], y[MAXN], ind[MAXN];
bool del[MAXN], can[MAXN];
vec<int> nodes;
unordered_set<int> G[MAXN];
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

void solve() {
	read(n), read(m), read(k);
	for(int i = 1; i <= n; ++i) G[i].clear(), ind[i] = 0; 
	S.clear(); nodes.clear();
	for(int i = 1; i <= m; ++i) {
		read(x[i], y[i]), ind[x[i]]++, ind[y[i]]++;
		G[x[i]].insert(y[i]);
		G[y[i]].insert(x[i]);
	}
	if(k > 500) return puts("-1"), void();
	for(int i = 1; i <= n; ++i) 
		S.insert(mp(ind[i], i)), del[i] = can[i] = false;
	while(S.size()) {
		auto now = *S.begin(); S.erase(S.begin());
		if(now.fst == k - 1) {
			int x = now.scd;
			//assert(G[x].size() == k - 1);
			bool flag = true;
			for(auto a : G[x]) {
				for(auto b : G[x]) {
					if(a == b) continue;
					if(!G[a].count(b)) {flag = false; break;}
				}
				if(!flag) break;
			}
			if(flag) {
				printf("2\n%d ", x);
				for(auto a : G[x]) printf("%d ", a);
				printf("\n");
				return;
			}
		}
		if(now.fst <= k - 1) {
			del[now.scd] = true;
			for(auto to : G[now.scd]) {
				if(del[to]) continue;
				S.erase(S.find(mp(ind[to], to)));
				ind[to]--; G[to].erase(now.scd);
				if(!ind[to]) continue;
				S.insert(mp(ind[to], to));
			}
			G[now.scd].clear();
		} else {
			printf("1 %d\n", S.size() + 1);
			printf("%d ", now.scd);
			for(auto x : S) printf("%d ", x.scd);
			printf("\n"); return void();
		}
	}
	puts("-1"); return void();
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}