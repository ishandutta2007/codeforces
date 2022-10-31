#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)

int main() {
    int v1, v2, t, d;
    rii(v1, v2); rii(t, d);
    int ans = v1; t--;
    while(t--) {
        int tmp = d;
        while(abs((v1 + tmp) - v2) > t * d) tmp--;
        v1 += tmp;
        ans += v1;
    }
    printf("%d\n", ans);
    return 0;
}