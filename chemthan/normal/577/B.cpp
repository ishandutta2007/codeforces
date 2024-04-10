#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxm = 1010;
int n, m;
int cnt[2][maxm];

void solve() {
	ms(cnt, 0);
	scanf("%d%d", &n, &m);
	bool flag = true;
	int k = 0;
	FOR(i, 0, n) {
		int a; scanf("%d", &a);
		FOR(j, 0, m) cnt[flag ^ 1][j] = cnt[flag][j];
		FOR(j, 0, m) cnt[flag ^ 1][(j + a) % m] += cnt[flag][j];
		cnt[flag ^ 1][a % m]++;
		flag ^= 1;
		if (++k > m) {printf("YES"); return;}
	}
	cnt[flag][0] ? printf("YES") : printf("NO");
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