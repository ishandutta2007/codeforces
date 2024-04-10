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

const int maxn = 100000 + 10;
int v[maxn << 2][62];
int ql, qr;
void ud(int o, int l, int r) {
    if(l == r) {
        rep(i, 60) v[o][i] = i % qr == 0 ? 2 : 1;
        return ;
    }
    int md = (l + r) >> 1;
    int lc = o << 1;
    int rc = lc + 1;
    if(ql <= md) ud(lc, l, md);
    else ud(rc, md + 1, r);
    rep(i, 60) v[o][i] = v[lc][i] + v[rc][(i + v[lc][i]) % 60];
}

int query(int o, int l, int r, int t) {
    // printf("qr %d %d %d - t = %d\n", o, l, r, t);
    if(ql <= l && qr >= r) {
        // printf("qr %d %d %d - t = %d -> %d\n", o, l, r, t, v[o][t]);
        return t + v[o][t % 60];
    }
    int md = (l + r) >> 1;
    int lc = o << 1;
    int rc = lc + 1;
    if(ql <= md) t = query(lc, l, md, t);
    if(qr > md) t = query(rc, md + 1, r, t);
    // printf("qr %d %d %d - t = %d -> %d\n", o, l, r, t, t);
    return t;
}

int main() {
    int n, q;
    ri(n);
    rep(i, n) {
        ri(qr);
        ql = i;
        ud(1, 0, n - 1);
    }
    char s[4];
    ri(q);
    rep(i, q) {
        scanf("%s%d%d", s, &ql, &qr);
        if(s[0] == 'C') {
            ql--;
            ud(1, 0, n - 1);
        }
        else {
            ql -= 1;
            qr -= 2;
            pi(query(1, 0, n - 1, 0));
        }
    }

    return 0;
}