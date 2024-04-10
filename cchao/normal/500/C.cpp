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

int n, m, w[1010], a[1010];
int vis[1010];
int main() {
    memset(vis, -1, sizeof vis);
    rii(n, m);
    ria(w, n);
    ria(a, m);

    int ans = 0;
    rep(i, m) {
        int j = i - 1;
        int tmp = 0;
        while(j >= 0 && a[j] != a[i]) {
            if(vis[a[j]] != i) tmp += w[a[j] - 1];
            vis[a[j]] = i;
            j--;
        }
        // printf("%d(%d): add %d\n", i, a[i], tmp);
        ans += tmp;
    }
    pi(ans);

    return 0;
}