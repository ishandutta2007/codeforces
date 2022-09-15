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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxn = 1000010;
int n, m;
string str[maxn];
map<string, int> order;
pi val[maxn];
int from[maxn];
int to[maxn];
vi adj[maxn];
vi radj[maxn];
vi vs;
int comp[maxn];
bool vis[maxn];
pi dmin[maxn];

int get(string s) {
    if (order.count(s)) return order[s];
    int res = order.size();
    return order[s] = res;
}

void tolower(string& s) {
    int cnt = 0;
    FOR(i, 0, sz(s)) {
        if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
        cnt += s[i] == 'r';
    }
    val[get(s)] = make_pair(cnt, s.size());
}

void dfs(int u) {
    vis[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
    }
    vs.push_back(u);
}

void rdfs(int u, int cnt) {
    comp[u] = cnt; vis[u] = 1;
    FOR(i, 0, sz(radj[u])) {
        int v = radj[u][i];
        if (!vis[v]) rdfs(v, cnt);
    }
}

void get(int u) {
    vis[u] = 1;
    FOR(i, 0, sz(adj[u])) {
        int v = adj[u][i];
        if (!vis[v]) get(v);
        if (dmin[u] > dmin[v]) dmin[u] = dmin[v];
    }
}

void solve() {
    cin>>n;
    FOR(i, 0, n) {cin>>str[i]; tolower(str[i]);}
    cin>>m;
    FOR(i, 0, m) {
        string a, b; cin>>a>>b;
        tolower(a); tolower(b);
        int u = get(a), v = get(b);
        adj[u].push_back(v);
        radj[v].push_back(u);
        from[i] = u; to[i] = v;
    }
    ms(vis, 0); FOR(i, 0, sz(order)) if (!vis[i]) dfs(i);
    ms(vis, 0); int cnt = 0;
    FORd(i, sz(vs), 0) {
        int u = vs[i];
        if (!vis[u]) rdfs(u, cnt++);
    }
    FOR(i, 0, cnt) dmin[i] = make_pair(INF, INF);
    FOR(i, 0, sz(order)) {
        int u = comp[i];
        if (dmin[u] > val[i]) dmin[u] = val[i];
    }
    FOR(i, 0, cnt) adj[i].clear();
    FOR(i, 0, m) {
        int u = comp[from[i]], v = comp[to[i]];
        if (u != v) adj[u].push_back(v);
    }
    ms(vis, 0); FOR(i, 0, cnt) if (!vis[i]) get(i);
    ll ans = 0, lans = 0;
    FOR(i, 0, n) {
        int u = comp[order[str[i]]];
        ans += dmin[u].first;
        lans += dmin[u].second;
    }
    cout<<ans<<" "<<lans;
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