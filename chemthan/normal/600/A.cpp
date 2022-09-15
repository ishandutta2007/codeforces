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
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos((ld) 0);

const int maxn = 100010;
string s;
vector<string> vs;

int check(string& t) {
	if (!sz(t)) return 0;
	if (sz(t) > 1 && t[0] == '0') return 0;
	FOR(i, 0, sz(t)) if (t[i] < '0' || t[i] > '9') return 0;
	return 1;
}

void solve() {
	cin>>s; s += ',';
	int n = sz(s);
	int cur = 0;
	FOR(i, 0, n) {
		if (s[i] == ',' || s[i] == ';') {
			vs.pb(s.substr(cur, i - cur));
			cur = i + 1;
		}
	}
	string a, b;
	FOR(i, 0, sz(vs)) {
		if (check(vs[i])) a += "," + vs[i];
		else b += "," + vs[i];
	}
	if (sz(a)) {
		a[0] = '\"';
		cout<<a<<"\""<<"\n";
	}
	else cout<<"-\n";
	if (sz(b)) {
		b[0] = '\"';
		cout<<b<<"\""<<"\n";
	}
	else cout<<"-\n";
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