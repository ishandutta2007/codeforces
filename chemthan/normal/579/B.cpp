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
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 410;
int n;
int p[2 * maxn];
vector<pair<int, pi> > v;

void solve() {
	ms(p, - 1);
	scanf("%d", &n);
	FOR(i, 1, 2 * n) FOR(j, 0, i) {int a; scanf("%d", &a); v.push_back(make_pair(-a, make_pair(i, j)));}
	sort(v.begin(), v.end());
	FOR(i, 0, sz(v)) {
		int x = v[i].second.first;
		int y = v[i].second.second;
		if (p[x] == -1 && p[y] == -1) {
			p[x] = y; p[y] = x;
		}
	}
	FOR(i, 0, 2 * n) printf("%d ", p[i] + 1);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}