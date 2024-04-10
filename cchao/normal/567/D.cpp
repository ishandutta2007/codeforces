#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, a, b) for(int i = a; i <= b; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define IO(name) freopen(name".in", "r", stdin);freopen(name".out", "w", stdout)
#define PB push_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 200010;
const double eps = 1e-8;

int s[maxn], len[maxn];
int n, k, a;

int sum(int x) {
    int ret = 0;
    for(; x; x -= (x&-x)) ret = max(ret, s[x]);
    return ret;
}

void add(int x, int v) {
    for(; x <= n; x += (x&-x)) s[x] = max(s[x], v);
}


int main() {
    
    riii(n, k, a);
    repe(i, 1, n) s[i] = 1;
    len[1] = n;

    int m; ri(m); int ans = -1;

    int cur = (n + 1) / (a + 1);

    repe(i, 1, m) {
        int x; ri(x);
        if(ans > 0) continue;
        int h = sum(x);
        int l = len[h];

        len[h] = x - h;
        len[x + 1] = l - len[h] - 1;

        cur -= (l + 1) / (a + 1);
        cur += (len[h] + 1) / (a + 1) + (len[x + 1] + 1) / (a + 1);
        add(x + 1, x + 1);
        if(cur < k) {
            ans = i;
        }
    }

    pi(ans);

    return 0;
}