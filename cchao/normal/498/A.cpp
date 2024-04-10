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

inline int sgn(long long x) {
    if(x == 0) return 0;
    return x < 0 ? -1 : 1;
}

int main() {
    int aa, bb, cc, dd;
    rii(aa, bb);
    rii(cc, dd);
    int ans = 0;
    int n; ri(n); while(n--) {
        int a, b, c; riii(a, b, c);
        if(sgn(1LL * aa * a + 1LL * bb * b + c) != sgn(1LL * cc * a + 1LL * dd * b + c))
            ans++;
    }
    pi(ans);
    return 0;
}