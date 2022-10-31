#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair

#define rep(i, n) for(int i = 0; i < n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)

char s[] = "RGBYW";

int n, a[110], b[110];

bool ok(int x) {
    int col = x >> 5;
    int num = x & 511;

    set<int> sa[5], sb[5];
    set<pii> sc;
    rep(i, n) {
        bool aa = ((1<<a[i]) & col);
        bool bb = ((1<<b[i]) & num);
        pii p = mp(a[i], b[i]);

        if(!aa && !bb) sc.insert(p);
        else if(!aa) sa[b[i]].insert(a[i]);
        else if(!bb) sb[a[i]].insert(b[i]);
    }

    for(int i = 0; i < 5; ++i) if(sa[i].size() > 1 || sb[i].size() > 1) return false;
    return sc.size() <= 1;
}

int main() {
    char t[4];
    ri(n);
    rep(i, n) {
        scanf("%s", t);
        a[i] = strchr(s, t[0]) - s;
        b[i] = t[1] - '1';
    }
    int ans = 10;
    rep(i, 1024) {
        if(ok(i)) ans = min(ans, __builtin_popcount(i));
    }
    pi(ans);
    return 0;
}