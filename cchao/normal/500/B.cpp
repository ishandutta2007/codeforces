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

int n, a[310];
char g[310][310];
vector<pii> v;
int p[310];
int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }

int main() {
    ri(n); ria(a, n);
    rep(i, n) scanf("%s", g[i]);
    rep(i, n) p[i] = i;
    rep(i, n) rep(j, i) if(g[i][j] == '1') p[f(i)] = f(j);
    rep(i, n) rep(j, i) if(f(i) == f(j)) v.push_back(pii(j, i));

    for(;;) {
        bool fg = false;
        for(auto x: v) {
            if(a[x.fst] > a[x.snd]) {
                fg = true;
                swap(a[x.fst], a[x.snd]);
            }
        }
        if(!fg) break;
    }

    pia(a, n);

    return 0;
}