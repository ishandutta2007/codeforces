#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))
#define mp make_pair

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}


const int MAXN = 4e5+5;
int a[MAXN], r[MAXN], n, k;
int nxt[MAXN], dp[MAXN], cnt, ans;
//vector<int> V[MAXN];
bool vis[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) r[i] = n + 1;
	for(int i = n; i >= 1; i--) {
		nxt[i] = r[a[i]];
		r[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) r[a[i]] = i;
	set< pair<int, int> > S;
	for(int i = 1; i <= n; i++) {
		if( i > 1 && r[a[i - 1]] == i - 1) S.erase(make_pair(-dp[a[i - 1]], a[i - 1])), cnt--;
		if(vis[a[i]]) {
			S.erase(make_pair(-dp[a[i]], a[i]));
			dp[a[i]] = nxt[i];
			S.insert(make_pair(-nxt[i], a[i]));
			continue;
		}
		if(cnt == k) {
			set< pair<int, int> > :: iterator it = S.begin();
			vis[it->second] = false;
			S.erase(it);
			cnt--;
		}
		cnt++;
		vis[a[i]] = true;
		S.insert(make_pair(-nxt[i], a[i]));
		dp[a[i]] = nxt[i];
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}