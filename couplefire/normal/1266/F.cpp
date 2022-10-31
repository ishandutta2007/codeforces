#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
 
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
 
ll fac[1], inv[1];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll mp(ll a,ll b){ll ret=1;while(b){if(b&1)ret=ret*a%MOD;a=a*a%MOD;b>>=1;}return ret;}
ll cmb(ll r, ll c) {return fac[r] * inv[c] % MOD * inv[r - c] % MOD;}
 
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v[500001];
 
int n;
int dist[500001];
int p[500001], cc[500001];
int up[500001];
int ans[1000005], mm[500001];
vector<int> adj[500001], g[500001];
 
int pre(int o, int pa) {
    p[o] = pa;
    int me = 0;
    for (int i : v[o]) {
        if (i != pa) {
            me = max(me, pre(i, o) + 1);
        }
    }
    return dist[o] = me;
}
 
void go(int o, int pa) {
    int m1 = up[o], m2 = 0, c = pa;
    for (int i : v[o]) {
        if (i != pa) {
            if (m1 < dist[i] + 1) {
                m2 = m1;
                m1 = dist[i] + 1;
                c = i;
            }
            else if (m2 < dist[i] + 1) m2 = dist[i] + 1;
        }
    }
 
    if (up[o]) adj[o].push_back(up[o]);
    for (int i : v[o]) {
        if (i != pa) {
            adj[o].push_back(dist[i] + 1);
            if (c == i) up[i] = m2 + 1;
            else up[i] = m1 + 1;
            go(i, o);
        }
    }
}
 
int main() {
    scanf("%d", &n);
 
    fill(ans + 1, ans + n + 1, 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
 
        ans[1] = max(ans[1], sz(v[a]) + 1);
        ans[1] = max(ans[1], sz(v[b]) + 1);
    }
    pre(0, 0);
    go(0, 0);
 
    for (int i = 0; i < n; i++) {
        sort(all(adj[i]), greater<int>());
        for (int j = 0; j < sz(adj[i]); j++) {
            int d = adj[i][j];
 
            if (j) {
                ans[d * 2] = max(ans[d * 2], j + 1);
                ans[d * 2 - 1] = max(ans[d * 2 - 1], j + 1);
                if (d < adj[i][j - 1]) ans[d * 2 + 1] = max(ans[d * 2 + 1], j + 1);
            }
            g[d].push_back(i);
        }
    }
 
    memset(mm, -0x3f, sizeof(mm));
    memset(cc, -1, sizeof(cc));
    for (int i = 0; i < n; i++)
        if (sz(v[i]) >= 2 || i == 0)
            mm[i] = -1;
 
    for (int i = n; i >= 1; i--) {
        for (int j : g[i]) {
            cc[j]++;
            ans[i * 2] = max(ans[i * 2], cc[j] + mm[j]);
 
            if (p[j] != j) {
                mm[p[j]] = max(mm[p[j]], cc[j]);
                ans[i * 2] = max(ans[i * 2], cc[p[j]] + mm[p[j]]);
            }
        }
    }
 
 
    for (int i = n - 2; i >= 1; i--) ans[i] = max(ans[i], ans[i + 2]);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}