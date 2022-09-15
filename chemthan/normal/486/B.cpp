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

const int maxn = 110;
int n, m;
int a[maxn][maxn];
int b[maxn][maxn];
bool S[maxn];
bool T[maxn];

void solve() {
    ms(S, 1); ms(T, 1);
    scanf("%d%d", &n, &m);
    FOR(i, 0, n) FOR(j, 0, m) scanf("%d", &b[i][j]);
    FOR(i, 0, n) FOR(j, 0, m) S[i] &= b[i][j];
    FOR(j, 0, m) FOR(i, 0, n) T[j] &= b[i][j];
    FOR(i, 0, n) FOR(j, 0, m) a[i][j] = S[i] & T[j];
    FOR(i, 0, n) FOR(j, 0, m) {
        int tmp = 0;
        FOR(k, 0, m) tmp |= a[i][k];
        FOR(k, 0, n) tmp |= a[k][j];
        if (tmp != b[i][j]) {printf("NO"); return;}
    }
    printf("YES\n");
    FOR(i, 0, n) {
        FOR(j, 0, m) printf("%d ", a[i][j]);
        printf("\n");
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