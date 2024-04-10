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

const int maxn = 2010;
int n;
int a[maxn];
int b[maxn];
vii res;

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", a + i);
    FOR(i, 0, n) {int x; scanf("%d", &x); b[x] = i;}
    FOR(i, 0, n) a[i] = b[a[i]];
    int ans = 0;
    FOR(i, 0, n) {
        int idx; FOR(j, i, n) if (a[j] == i) {idx = j; break;}
        FORd(j, idx, i) if (a[j] >= idx) {
            swap(a[idx], a[j]); res.push_back(make_pair(idx, j));
            ans += idx - j;
            idx = j;
        }
    }
    printf("%d\n%d\n", ans, sz(res));
    FOR(i, 0, sz(res)) printf("%d %d\n", res[i].first + 1, res[i].second + 1);
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