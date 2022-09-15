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

const int maxn = 100010;
const int mod = 1000000007;
int n, k;
ll f[maxn];

void solve() {
    int t; scanf("%d%d", &t, &k);
    FOR(i, 0, k) f[i] = 1;
    FOR(i, k, maxn) f[i] = (f[i - 1] + f[i - k]) % mod;
    FOR(i, 1, maxn) f[i] = (f[i] + f[i - 1]) % mod;
    while (t--) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%I64d\n", (f[b] - f[a - 1] + mod) % mod);
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