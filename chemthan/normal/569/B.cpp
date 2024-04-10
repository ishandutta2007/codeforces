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

const int maxn = 100010;
int n;
int a[maxn];
int flag1[maxn];
int flag2[maxn];

void solve() {
	ms(flag1, 0); ms(flag2, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", a + i);
		flag1[a[i]] = 1;
	}
	int cur = 1;
	FOR(i, 0, n) {
		if (!flag2[a[i]] && a[i] <= n) {
			flag1[a[i]] = 1;
			flag2[a[i]] = 1;
			printf("%d ", a[i]);
		}
		else {
			while (cur <= n && flag1[cur]) cur++;
			flag1[cur] = 1;
			printf("%d ", cur);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}