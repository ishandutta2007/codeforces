#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

const int maxn = 100010;
vector<int> g[maxn];
int l[maxn], a[maxn], b[maxn], n, sz[maxn], esz[maxn];
int q, aa, bb;

int dfs(int x, int fe = -1) {
    sz[x] = 1;
    for(auto e: g[x]) {
        if(e == fe) continue;
        int y = a[e] == x ? b[e] : a[e];
        sz[x] += dfs(y, e);
    }
    if(fe >= 0) esz[fe] = sz[x];
    return sz[x];
}

int main() {

    ri(n);
    rep(i, n - 1) {
        riii(a[i], b[i], l[i]);
        g[a[i]].pb(i);
        g[b[i]].pb(i);
    }
    dfs(1);
    double cur = 0;
    rep(i, n - 1) {
        cur += 1.0 * esz[i] * (n - esz[i]) * l[i];
    }
    // printf("%f\n", cur / (n * (n - 1)) * 6);

    ri(q);
    rep(i, q) {
        rii(aa, bb);
        aa--;
        cur -= 1.0 * esz[aa] * (n - esz[aa]) * l[aa];   
        l[aa] = bb;
        cur += 1.0 * esz[aa] * (n - esz[aa]) * l[aa];   
        printf("%.12f\n", cur / (1.0 * n * (n - 1.0)) * 6);
    }

    return 0;
}