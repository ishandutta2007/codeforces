#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int readInt() {
    int f = 1, x = 0;
    char c = getchar();
    while(!isdigit(c)) {
        if(c == '-')
            f = -f;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}
 
ll readLL() {
    ll f = 1, x = 0;
    char c = getchar();
    while(!isdigit(c)) {
        if(c == '-')
            f = -f;
        c = getchar();
    }
    while(isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}
 
ll qmul(ll a, ll b, ll mod) {
    if(a >= mod)
        a %= mod;
    ll res = 0;
    while(b) {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
 
ll qpow(ll a, ll b, ll mod) {
    if(a >= mod)
        a %= mod;
    ll res = 1;
    while(b) {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
/* ---- begin ---- */
 
const int INF = 0x3f3f3f3f;
 
int n, m;
int a[1000005];
int b[1000005];
int X[1000005];
 
pii pa[20005];
 
const int N = 1e6;
 
void solve() {
    scanf("%d%d", &n, &m);
    memset(a, INF, sizeof(a));
    memset(b, -INF, sizeof(b));
    for(int i = 1; i <= n; ++i) {
        int ax, ay;
        scanf("%d%d", &ax, &ay);
        a[ax] = min(a[ax], ay);
    }
    for(int i = 1; i <= N; ++i)
        a[i] = min(a[i], a[i - 1]);
    for(int i = 1; i <= m; ++i) {
        int bx, by;
        scanf("%d%d", &bx, &by);
        b[bx] = max(b[bx], by);
    }
    for(int i = N - 1; i >= 0; --i)
        b[i] = max(b[i], b[i + 1]);
    int cnta = 0;
    pa[++cnta] = {0, a[0]};
    for(int i = 1; i <= N; ++i) {
        if(a[i] != a[i - 1])
            pa[++cnta] = {i, a[i]};
    }
    srand(time(0));
    // random_shuffle(pa + 1, pa + 1 + cnta);
 
    const int NN = N + 5;
    for(int x = 0; x <= NN; ++x)
        X[x] = x;
    // random_shuffle(X, X + NN + 1);
    int ans = INF;
    for(int xi = 0; xi <= NN; ++xi) {
        int x = X[xi];
        if(x >= ans)
            continue;
        int y = 0;
        for(int i = 1; i <= cnta; ++i) {
            int ax = pa[i].first, ay = pa[i].second;
            if(ax + x > N)
                continue;
            int d = max(0, b[ax + x] - ay + 1);
            y = max(y, d);
            if(x + y >= ans)
                break;
        }
        ans = min(ans, x + y);
    }
    printf("%d\n", ans);
    return;
}
 
int main() {
#ifdef purinliang
    freopen("A.txt", "r", stdin);
#endif // purinliang
    //init();
    int T = 1;
    //scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        //printf("Case #%d: ", t);
        solve();
    }
    return 0;
}