#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int n, m, k;

const int NMAX = 1100;

int par[NMAX];
int sz[NMAX];
int ed[NMAX];
int spec[NMAX];

void setup() {
    for(int i=0;i<NMAX;++i) {
        par[i] = -1;
        sz[i] = 1;
    }
}

int FIND(int u) {
    if(par[u] == -1) return u;
    return par[u] = FIND(par[u]);
}

void UNION(int u, int v) {
    if(FIND(u) == FIND(v)) {
        ed[FIND(u)]++;
        return;
    }
    sz[FIND(u)] += sz[FIND(v)];
    ed[FIND(u)] += ed[FIND(v)]+1;
    spec[FIND(u)] |= spec[FIND(v)];
    par[FIND(v)] = FIND(u);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    setup();
    for(int i=1;i<=k;++i) {
        int c;
        cin >> c;
        spec[c]=1;
    }
    for(int i=0;i<m;++i) {
        int u, v;
        cin >> u >> v;
        UNION(u, v);
    }
    ll f = 0, r = 0;
    for(int i=1;i<=n;++i) {
        if(FIND(i) == i && !spec[i]) {
            f+=sz[i];
            r+=ed[i];
        }
    }
    ll ans = 0;
    ll base = 0;
    for(int i=1;i<=n;++i) {
        if(FIND(i) == i && spec[i]) {
            base += sz[i]*(sz[i]-1)/2-ed[i];
            ans = max(ans, (f+sz[i])*(f+sz[i]-1)/2-r-sz[i]*(sz[i]-1)/2);
        }
    }
    cout << ans+base << endl;
    return 0;
}