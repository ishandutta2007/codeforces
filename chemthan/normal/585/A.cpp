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
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

const int maxn = 4010;
int n;
int v[maxn];
int d[maxn];
int p[maxn];
vector<pair<pi, pi> > q;
vi ans;

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) {
        scanf("%d%d%d", v + i, d + i, p + i);
        q.push_back(make_pair(make_pair(v[i], d[i]), make_pair(p[i], i)));
    }
    reverse(q.begin(), q.end());
    while (sz(q)) {
        pair<pi, pi> k = q.back(); q.pop_back();
        ll cnt = k.first.first;
        FORd(i, sz(q), 0) if (cnt) q[i].second.first -= cnt--;
        vector<pair<pi, pi> > tmp;
        ll tot = 0;
        FORd(i, sz(q), 0) {
            if (q[i].second.first < tot) tot += q[i].first.second;
            else {
                q[i].second.first -= tot;
                tmp.push_back(q[i]);
            }
        }
        reverse(tmp.begin(), tmp.end());
        q = tmp;
        ans.push_back(k.second.second);
    }
    printf("%d\n", sz(ans));
    FOR(i, 0, sz(ans)) printf("%d ", ans[i] + 1);
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