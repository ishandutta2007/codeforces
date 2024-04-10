#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 110;
int n;
string s[maxn];

void solve() {
	cin>>n; FOR(i, 0, n) cin>>s[i];
	int ans = 0;
	FOR(i, 'a', 'z' + 1) FOR(j, i + 1, 'z' + 1) {
		int tot = 0;
		FOR(k, 0, n) {
			bool flag = 1;
			FOR(l, 0, sz(s[k])) if (s[k][l] != i && s[k][l] != j) {flag = 0; break;}
			if (flag) tot += sz(s[k]);
		}
		ans = max(ans, tot);
	}
	cout<<ans;
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