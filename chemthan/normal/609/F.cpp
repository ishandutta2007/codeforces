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
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

const int maxn = 200010;
int n, m;
int x[maxn];
ll t[maxn];
int p[maxn];
int b[maxn];
map<int, int> dc;
int a[maxn];
int rb[maxn];
int ans[maxn];

ll bit[maxn];
void update(int p, ll val) {
	for (; p < maxn; p += p & -p) bit[p] = max(bit[p], val);
}
ll query(int p) {
	ll res = 0;
	for (; p > 0; p -= p & -p) res = max(res, bit[p]);
	return res;
}

void solve() {
//	int T; cin>>T;
//	while (T--) {
		dc.clear(); ms(bit, 0);
		cin>>n>>m;
		vii v;
		FOR(i, 0, n) {
			cin>>x[i]>>t[i];
			dc[x[i]]; v.pb(mp(x[i], i));
		}
		FOR(i, 0, m) cin>>p[i]>>b[i];
		int cnt = 0;
		FORall(it, dc) it->se = cnt++;
		FOR(i, 0, n) {a[i] = dc[x[i]] + 1; rb[a[i]] = i;}
		FOR(i, 0, n) update(a[i], x[i] + t[i]);
		sort(all(v)); set<pi> st;
		FOR(i, 0, m) {
			int l = 1, r = upper_bound(all(v), mp(p[i], INF << 1)) - v.begin();
			if (r) {
				while (l < r) {
					int mid = (l + r) >> 1;
					if (query(mid) < p[i]) l = mid + 1; else r = mid;
				}
				if (query(l) >= p[i]) {
					int idx = rb[l];
					t[idx] += b[i]; ans[idx]++;
					vii his;
					set<pi>::iterator it = st.lower_bound(mp(x[idx], -INF));
					while (it != st.end()) {
						int u = it->fi;
						int v = it->se;
						if (x[idx] + t[idx] >= u) {
							t[idx] += b[v]; ans[idx]++;
							his.pb(mp(u, v));
						}
						else break;
						it++;
					}
					FOR(j, 0, sz(his)) st.erase(his[j]);
					update(a[idx], x[idx] + t[idx]);
				}
				else st.insert(mp(p[i], i));
			}
			else st.insert(mp(p[i], i));
		}
		FOR(i, 0, n) {
			cout<<ans[i]<<" "<<t[i]<<"\n";
		}
//	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}