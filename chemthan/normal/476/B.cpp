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

char s[20];
char t[20];
int C[20][20];

void solve() {
	FOR(i, 0, 20) C[0][i] = 1;
	FOR(i, 1, 20) FOR(j, 1, 20) C[i][j] = C[i][j - 1] + C[i - 1][j - 1];
	scanf("%s%s", s, t);
	int a = 0, b = 0, c = 0;
	FOR(i, 0, strlen(s)) {
		if (s[i] == '+') a++; else a--;
		if (t[i] == '+') b++;
		else if (t[i] == '-') b--;
		else c++;
	}
	if ((c + a - b) % 2 == 1) cout<<prec(9)<<0.0;
	else {
		int x = (c + a - b) >> 1;
		int y = (c - a + b) >> 1;
		if (x < 0 || x > c) cout<<prec(9)<<0.0;
		else cout<<prec(9)<<C[x][c] / pow(2.0, c);
	}
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