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

const int maxn = 160;
int n, m;
map<int, vii> g;
vi adj[maxn], v;
int dis[maxn];

struct matrix {
    bitset<maxn> x[maxn];
};

matrix mul(matrix A, matrix B) {
    matrix res, tmp;
    FOR(i, 0, maxn) FOR(j, 0, maxn) tmp.x[i][j] = B.x[j][i];
    FOR(i, 0, maxn) FOR(j, 0, maxn) res.x[i][j] = (A.x[i] & tmp.x[j]).any();
    return res;
}

matrix ex(matrix A, int k) {
    if (k == 1) return A;
    matrix res = A, tmp = A; k--;
    while (k) {
        if (k & 1) res = mul(res, tmp);
        tmp = mul(tmp, tmp);
        k >>= 1;
    }
    return res;
}

void solve() {
    scanf("%d%d", &n, &m);
    FOR(i, 0, m) {
        int a, b, d; scanf("%d%d%d", &a, &b, &d);
        a--; b--; g[d].push_back(make_pair(a, b));
    }
    g[0].push_back(make_pair(n, n));
    g[INT_MAX].push_back(make_pair(0, 0));
    for (map<int, vii>::iterator it = g.begin(); it != g.end(); it++) v.push_back(it->first);
    int ans = 0x3f3f3f3f;
    matrix cur, can; can.x[0][0] = 1;
    FOR(i, 0, sz(v) - 1) {
        vii edges = g[v[i]];
        FOR(j, 0, sz(edges)) {
            int u = edges[j].first;
            int v = edges[j].second;
            cur.x[u][v] = 1;
            adj[u].push_back(v);
        }
        FOR(j, 0, n) if (can.x[0][j]) {
            ms(dis, 0x3f); dis[j] = v[i];
            priority_queue<pair<int, int> > pq; pq.push(make_pair(-dis[j], j));
            while (sz(pq)) {
                int u = pq.top().second; pq.pop();
                FOR(k, 0, sz(adj[u])) {
                    int v = adj[u][k];
                    if (dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1;
                        pq.push(make_pair(-dis[v], v));
                    }
                }
            }
            ans = min(ans, dis[n - 1]);
        }
        can = mul(can, ex(cur, v[i + 1] - v[i]));
    }
    if (ans < 0x3f3f3f3f) printf("%d", ans); else printf("Impossible");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    solve();
#ifdef _LOCAL_
    printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}