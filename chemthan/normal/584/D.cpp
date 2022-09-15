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
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

int n;

bool checkprime(int k) {
    if (k < 2) return 0;
    for (int i = 2; i * i <= k; i++) if (k % i == 0) return 0;
    return 1;
}

void solve() {
    scanf("%d", &n);
    if (n == 3) {printf("1\n3"); return;}
    FORd(i, n + 1, 2) if (checkprime(i)) {
        int r = n - i;
        if (r == 0) {printf("1\n%d", n); return;}
        if (checkprime(r)) {printf("2\n%d %d", i, r); return;}
        FOR(j, 1, r) if (checkprime(j) && checkprime(r - j)) {
            printf("3\n%d %d %d", i, j, r - j);
            return;
        }
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