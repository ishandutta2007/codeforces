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

const long long mod = 1000000007;
long long a[100010] = {1};
int main() {
    int t, k; rii(t, k);
    a[1] = (k == 1) ? 2 : 1;
    for(int i = 2; i <= 100000; ++i) {
        a[i] += a[i-1];
        if(i - k >= 0) a[i] += a[i-k];
        a[i] %= mod;
    }
    
    for(int i = 2; i <= 100000; ++i) a[i] = (a[i] + a[i-1]) % mod;
    a[0] = 0;
    // rep(i, 5) cout << a[i] << endl;
    // puts("--");
    while(t--) {
        int l, r; rii(l, r);
        // cout << l << ' ' << r << ' ';
        long long ans = ((a[r] - a[l-1]) % mod + mod) % mod;
        cout << ans << endl;
    }

    return 0;
}