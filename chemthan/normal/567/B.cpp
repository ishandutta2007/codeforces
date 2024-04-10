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

const int maxn = 1000010;
int n;
bool flag[maxn];
vi v1, v2;

void solve() {
	ms(flag, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {
		char s[10]; int r; scanf("%s%d", s, &r);
		if (s[0] == '+') {
			flag[r] = 1;
			v1.push_back(1);
		}
		else {
			if (!flag[r]) v2.push_back(1);
			flag[r] = 0;
			v1.push_back(0);
		}
	}
	FOR(i, 0, sz(v1)) v2.push_back(v1[i]);
	int cnt = 0;
	int ans = 0;
	FOR(i, 0, sz(v2)) {
		if (v2[i]) cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}
	printf("%d", ans);
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