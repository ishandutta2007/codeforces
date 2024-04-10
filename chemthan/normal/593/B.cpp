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

const int maxn = 100010;
int n;
double x[2];
double k[maxn];
double b[maxn];

void solve() {
	cin>>n>>x[0]>>x[1];
	x[0] += EPS; x[1] -= EPS;
	vector<pair<double, double> > v;
	FOR(i, 0, n) {
		cin>>k[i]>>b[i];
		double p = k[i] * x[0] + b[i];
		double q = k[i] * x[1] + b[i];
		v.push_back(make_pair(p, q));
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n - 1) if (v[i].second >= v[i + 1].second) {cout<<"YES"; return;}
	cout<<"NO";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}