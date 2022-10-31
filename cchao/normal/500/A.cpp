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

int a[100000], n, t;
bool vis[100000] = {};
int main() {
    rii(n, t);
    for(int i = 1; i <= n - 1; ++i) ri(a[i]);
    int cur = 1;

    while(cur != t && !vis[cur]) {
        vis[cur] = true;
        cur = cur + a[cur];
    }

    puts(cur == t ? "YES" : "NO");

    return 0;
}