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

const int maxn = 200010;
int n;
int a[maxn];
bool state[maxn];

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", a + i);
    ll ans = 0;
    FOR(d, 1, n) if (n % d == 0) {
        ms(state, 0); int cnt = 0, t;
        FOR(r, 0, d) {
            int dmax = 0;
            for (int i = r; i < n; i += d) dmax = max(dmax, a[i]);
            for (int i = r; i < n; i += d) {
                state[i] = a[i] == dmax;
                cnt += state[i];
                if (!state[i]) t = i;
            }
        }
        vi v;
        if (cnt == n) v.push_back(n);
        else {
            cnt = 0;
            FOR(i, 0, n) {
                if (!state[(i + t) % n]) {
                    if (cnt) v.push_back(cnt);
                    if (i >= n) break;
                    cnt = 0;
                }
                else cnt++;
                if (i == n - 1 && cnt) v.push_back(cnt);
            }
        }
        FOR(i, 0, sz(v)) {
            int k = v[i];
            if (k < n) {
                for (int c = 1; c * d <= k; c++) if (gcd(c, n / d) == 1) ans += k - c * d + 1;
            }
            else {
                for (int c = 1; c * d < n; c++) if (gcd(c, n / d) == 1) ans += n;
            }
        }
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