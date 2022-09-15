#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 110;
int n, m;
int v[maxn];

void solve() {
	ms(v, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, m) {
		int tmp = 0, iwin = 0;
		FOR(j, 0, n) {
			int a;
			scanf("%d", &a);
			if (tmp < a) {tmp = a; iwin = j;};
		}
		v[iwin]++;
	}
	int tmp = 0, iwin = 0;
	FOR(i, 0, n) {
		if (tmp < v[i]) {tmp = v[i]; iwin = i;}
	}
	printf("%d", iwin + 1);
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}