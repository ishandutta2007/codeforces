#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-7
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 110;
const int maxm = 1010;
int n, m;
int x[maxm];
double f[maxn][maxn * maxm];
double sum[maxn * maxm];

void solve() {
	cin>>n>>m;
	if (m == 1) {cout<<1; return;}
	int tot = 0;
	FOR(i, 1, n + 1) {
		cin>>x[i];
		tot += x[i];
	}
	f[0][0] = m - 1;
	FOR(i, 1, n + 1) {
		FOR(j, 0, n * m + 1) {
			if (!j) sum[j] = f[i - 1][j] / (m - 1);
			else sum[j] = sum[j - 1] + f[i - 1][j] / (m - 1);
		}
		FOR(j, 1, n * m + 1) {
			f[i][j] = sum[j - 1];
			if (j - m - 1 >= 0) f[i][j] -= sum[j - m - 1];
			if (j - x[i] >= 0)
				f[i][j] -= f[i - 1][j - x[i]] / (m - 1);
		}
	}
	double res = 0;
	FOR(i, 1, tot) res += f[n][i];
	cout<<fixed<<setprecision(9)<<res + 1;
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}