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

int n;

void solve() {
    scanf("%d", &n);
    if (n <= 3) {printf("NO"); return;}
    printf("YES\n");
    if (n == 4) {
        printf("1 + 2 = 3\n");
        printf("3 + 3 = 6\n");
        printf("4 * 6 = 24");
        return;
    }
    if (n == 5) {
        printf("4 + 5 = 9\n");
        printf("1 + 9 = 10\n");
        printf("10 - 2 = 8\n");
        printf("3 * 8 = 24");
        return;
    }
    printf("3 - 2 = 1\n");
    printf("1 - 1 = 0\n");
    FOR(i, 1, n + 1) if (i > 4 && i != 6) printf("0 * %d = 0\n", i);
    printf("4 * 6 = 24\n");
    printf("24 + 0 = 24");
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