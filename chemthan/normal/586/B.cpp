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

const int maxn = 100;
int n;
int a[2][maxn];
int b[maxn];

void solve() {
    scanf("%d", &n);
    FOR(i, 0, 2) FOR(j, 0, n - 1) scanf("%d", &a[i][j]);
    FOR(i, 0, n) scanf("%d", &b[i]);
    vector<int> v;
    FOR(i, 0, n) {
        int tmp = 0;
        FOR(j, 0, i) tmp += a[0][j];
        tmp += b[i];
        FOR(j, i, n - 1) tmp += a[1][j];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    printf("%d", v[0] + v[1]);
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