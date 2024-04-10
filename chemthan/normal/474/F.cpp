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

struct segment {
    int min, cnt;
    int gcd;

    segment() {
        min = INT_MAX;
        gcd = 0;
    }
} null;

segment merge(segment st1, segment st2) {
    segment res;
    res.min = min(st1.min, st2.min);
    if (st1.min == st2.min) res.cnt = st1.cnt + st2.cnt;
    else if (st1.min < st2.min) res.cnt = st1.cnt;
    else res.cnt = st2.cnt;
    res.gcd = gcd(st1.gcd, st2.gcd);
    return res;
}

const int maxn = 100010;
int n;
int s[maxn];

segment st[4 * maxn];
void build(int node, int L, int R) {
    if (L == R) {st[node].min = st[node].gcd = s[L]; st[node].cnt = 1; return;}
    build(node << 1, L, (L + R) >> 1);
    build((node << 1) + 1, ((L + R) >> 1) + 1, R);
    st[node] = merge(st[node << 1], st[(node << 1) + 1]);
}
segment query(int node, int l, int r, int L, int R) {
    if (l > R || r < L) return null;
    if (l <= L && r >= R) return st[node];
    return merge(query(node << 1, l, r, L, (L + R) >> 1), query((node << 1) + 1, l, r, ((L + R) >> 1) + 1, R));
}

void solve() {
    scanf("%d", &n);
    FOR(i, 0, n) scanf("%d", s + i);
    build(1, 0, n - 1);
    int t; scanf("%d", &t);
    while (t--) {
        int l, r; scanf("%d%d", &l, &r); l--; r--;
        segment res = query(1, l, r, 0, n - 1);
        int ans = r - l + 1; if (res.gcd == res.min) ans -= res.cnt;
        printf("%d\n", ans);
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