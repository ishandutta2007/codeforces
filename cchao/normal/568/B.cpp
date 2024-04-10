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
#define EB emplace_back
#define MP make_pair
#define F first
#define S second

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;
const int mod = 1000000007;
int d[4010][4010];
bool v[4010][4010]={};
int S(int x, int y) {
    int &ret = d[x][y];
    if(v[x][y]) return ret;
    v[x][y] = true;

    if(x == y || y == 1) return ret = 1;
    return ret = (1LL * S(x - 1, y - 1) + 1LL * y * S(x - 1, y)) % mod;
}
int main() {
    int n; ri(n);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = (ans + 1LL * S(n, i) * i) % mod;
    pi(ans);
    return 0;
}