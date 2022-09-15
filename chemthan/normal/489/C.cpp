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

int m, s;

void solve() {
	scanf("%d%d", &m, &s);
	if (s == 0 && m == 1) {printf("0 0"); return;}
	if (s == 0 || 9 * m < s) {printf("-1 -1"); return;}
	int tmp = s, cur = m;
	while (cur) {
		FOR(i, 0, 10) {
			if ((cur < m || i) && tmp - i >= 0 && tmp - i <= 9 * (cur - 1)) {
				printf("%d", i);
				tmp -= i;
				cur--;
				break;
			}
		}
	}
	printf(" ");
	tmp = s, cur = m;
	while (cur) {
		FORd(i, 10, 0) if (tmp - i >= 0 && tmp - i <= 9 * (cur - 1)) {
			printf("%d", i);
			tmp -= i;
			cur--;
			break;
		}
	}
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