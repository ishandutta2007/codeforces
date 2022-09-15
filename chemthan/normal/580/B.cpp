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

const int maxn = 100010;
int n, d;
int m[maxn];
int s[maxn];
vii v;
ll sum[maxn];

void solve() {
    ms(sum, 0);
    scanf("%d%d", &n, &d);
    FOR(i, 0, n) {
        scanf("%d%d", m + i, s + i);
        v.push_back(make_pair(m[i], s[i]));
    }
    sort(v.begin(), v.end());
    FOR(i, 0, n) sum[i + 1] = sum[i] + v[i].second;
    ll ans = 0;
    FOR(i, 0, n) {
        int k = upper_bound(v.begin(), v.end(), make_pair(v[i].first + d - 1, _I64_MAX)) - v.begin();
        ans = max(ans, sum[k] - sum[i]);
    }
    printf("%I64d", ans);
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