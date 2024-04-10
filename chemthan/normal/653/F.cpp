#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcount(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> void setmin(T& a, T val) {if (a > val) a = val;}
template<class T> void setmax(T& a, T val) {if (a < val) a = val;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int MAXN = 500010;
struct SuffixArray {
	char T[MAXN];
	int nsz;
	int RA[MAXN], tmpRA[MAXN];
	int SA[MAXN], tmpSA[MAXN];
	int c[MAXN];
	int Phi[MAXN], PLCP[MAXN];
	int LCP[MAXN];
	void init(char* str) {
		strcpy(T, str);
		nsz = strlen(T);
		for (int i = 0; i < nsz; i++) {
			RA[i] = tmpRA[i] = 0;
			SA[i] = tmpSA[i] = 0;
			Phi[i] = PLCP[i] = LCP[i] = 0;
		}
		constructSA();
		computeLCP();
	}
	void countingsort(int k) {
		int sum = 0, maxi = max(300, nsz);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < nsz; i++) c[i + k < nsz ? RA[i + k] : 0]++;
		for (int i = 0; i < maxi; i++) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (int i = 0; i < nsz; i++) tmpSA[c[SA[i] + k < nsz ? RA[SA[i] + k] : 0]++] = SA[i];
		for (int i = 0; i < nsz; i++) SA[i] = tmpSA[i];
	}
	void constructSA() {
		int r;
		for (int i = 0; i < nsz; i++) RA[i] = T[i];
		for (int i = 0; i < nsz; i++) SA[i] = i;
		for (int k = 1; k < nsz; k <<= 1) {
			countingsort(k);
			countingsort(0);
			tmpSA[SA[0]] = r = 0;
			for (int i = 1; i < nsz; i++) tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			for (int i = 0; i < nsz; i++) RA[i] = tmpRA[i];
			if (RA[SA[nsz - 1]] == nsz - 1) break;
		}
	}
	void computeLCP() {
		int L = 0;
		Phi[SA[0]] = -1;
		for (int i = 1; i < nsz; i++) Phi[SA[i]] = SA[i - 1];
		for (int i = 0; i < nsz; i++) {
			if (!~Phi[i]) {PLCP[i] = 0; continue;}
			while (T[i + L] == T[Phi[i] + L]) L++;
			PLCP[i] = L;
			L = max(L - 1, 0);
		}
		for (int i = 0; i < nsz; i++) LCP[i] = PLCP[SA[i]];
	}
} sa;

const int maxn = 500010;
const int maxe = 20;
int n;
string s;
int a[maxn];
int nxt[maxn][maxe];
int lst[maxn << 1];
int x[maxn];

int st[4 * maxn];
void update(int node, int i, int L, int R, int val) {
	if (i < L || i > R) return;
	if (L == R) {
		st[node] = val;
		return;
	}
	update(node << 1, i, L, (L + R) >> 1, val);
	update((node << 1) + 1, i, ((L + R) >> 1) + 1, R, val);
	st[node] = min(st[node << 1], st[(node << 1) + 1]);
}
int query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return INF;
	if (l <= L && r >= R) return st[node];
	return min(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

int jump(int u, int v) {
	if (u == v) return u;
	FORd(i, maxe, 0) {
		if (nxt[u][i] <= v) {
			u = nxt[u][i];
		}
	}
	return u;
}

void solve() {
	cin>>n>>s;
	sa.init((char*) (s + "$").data());
	FOR(i, 0, n) {
		a[i] = s[i] == '(' ? 1 : -1;
	}
	FOR(i, 1, n) a[i] += a[i - 1];
	FOR(i, 0, n + 1) nxt[i][0] = n;
	fill_n(lst, n, -1); fill_n(st, 4 * n, INF);
	FOR(i, 0, n) update(1, i, 0, n - 1, a[i]);
	FORd(i, n, 0) {
		if (s[i] == '(') {
			if (~lst[a[i] - 1 + n]) {
				if (query(1, i, lst[a[i] - 1 + n], 0, n - 1) == a[i] - 1) {
					nxt[i][0] = lst[a[i] - 1 + n] + 1;
					x[i] = x[nxt[i][0]] + 1;
				}
			}
		}
		else {
			lst[a[i] + n] = i;
		}
	}
	FOR(j, 1, maxe) {
		FOR(i, 0, n + 1) {
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		}
	}
	ll ans = 0;
	FOR(i, 1, n + 1) if (s[sa.SA[i]] == '(') {
		int k = sa.LCP[i];
		int idx = jump(sa.SA[i], sa.SA[i] + k);
		ans += x[idx];
	}
	cout<<ans<<"\n";
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}