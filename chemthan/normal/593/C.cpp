#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back
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
#define EPS 1e-9
const int mod = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 60;
int n;
int x[maxn];
int y[maxn];
int r[maxn];

string combine(string a, string b, string op) {
	return "(" + a + op + b + ")";
}

void solve() {
	cin>>n;
	FOR(i, 0, n) cin>>x[i]>>y[i]>>r[i];
	string res;
	FOR(i, 0, n) {
		char buf[10];
		itoa(i, buf,10);
		string t = string("abs((t-") + buf + "))";
		itoa(x[i] / 2, buf,10);
		if (!sz(res)) res = string("(") + buf + string("*((1-") + t + ")+abs((" + t + "-1))))";
		else res = combine(res, string("(") + buf + string("*((1-") + t + ")+abs((" + t + "-1))))", "+");
	}
	cout<<res<<"\n";
	res = "";
	FOR(i, 0, n) {
		char buf[10];
		itoa(i, buf,10);
		string t = string("abs((t-") + buf + "))";
		itoa(y[i] / 2, buf,10);
		if (!sz(res)) res = string("(") + buf + string("*((1-") + t + ")+abs((" + t + "-1))))";
		else res = combine(res, string("(") + buf + string("*((1-") + t + ")+abs((" + t + "-1))))", "+");
	}
	cout<<res<<"\n";
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