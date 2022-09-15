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
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 100010;
int n, d;
ll h[maxn];
vii v;
int p[maxn];
int f[maxn];
int nxt[maxn];

int st[4 * maxn];
void build(int node, int L, int R) {
    if (L == R) {st[node] = L; return;}
    build(node << 1, L, (L + R) >> 1);
    build((node << 1) + 1, ((L + R) >> 1) + 1, R);
    st[node] = st[node << 1];
}
void update(int node, int i, int L, int R) {
    if (i < L || i > R) return;
    if (L == R) {st[node] = L; return;}
    update(node << 1, i, L, (L + R) >> 1);
    update((node << 1) + 1, i, ((L + R) >> 1) + 1, R);
    int p = st[node << 1];
    int q = st[(node << 1) + 1];
    st[node] = f[p] > f[q] ? p : q;
}
int query(int node, int l, int r, int L, int R) {
    if (l > R || r < L) return -1;
    if (l <= L && r >= R) return st[node];
    int p = query(node << 1, l, r, L, (L + R) >> 1);
    int q = query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R);
    if (p == -1) return q;
    if (q == -1) return p;
    return f[p] > f[q] ? p : q;
}

void solve() {
    scanf("%d%d", &n, &d);
    FOR(i, 0, n) {scanf("%I64d", h + i); v.push_back(make_pair(h[i], i));}
    sort(v.begin(), v.end());
    FOR(i, 0, n) p[v[i].second] = i;
    int ans = 0, ians;
    build(1, 0, n - 1);
    FORd(i, n, 0) {
        f[p[i]] = 1; nxt[i] = -1;
        int k = lower_bound(v.begin(), v.end(), make_pair(h[i] + d, _I64_MIN)) - v.begin();
        int l = upper_bound(v.begin(), v.end(), make_pair(h[i] - d, _I64_MAX)) - v.begin();
        if (k < n) {
            int idx = query(1, k, n - 1, 0, n - 1);
            if (f[p[i]] < 1 + f[idx]) {
                f[p[i]] = 1 + f[idx];
                nxt[i] = v[idx].second;
            }
        }
        if (l > 0) {
            int idx = query(1, 0, l - 1, 0, n - 1);
            if (f[p[i]] < 1 + f[idx]) {
                f[p[i]] = 1 + f[idx];
                nxt[i] = v[idx].second;
            }
        }
        update(1, p[i], 0, n - 1);
        if (ans < f[p[i]]) {ans = f[p[i]]; ians = i;}
    }
    printf("%d\n", ans);
    while (ians != -1) {printf("%d ", ians + 1); ians = nxt[ians];}
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