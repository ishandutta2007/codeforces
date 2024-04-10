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

vector<int> pos, neg;
int zero = 0;
int n, k;

map<ll, int> m1, m2;
int d1[maxn];
ll solve(vector<int> &a) {
    m1 = map<ll, int>();
    m2 = map<ll, int>();
    int n = a.size();

    rep(i, n) {
        if(a[i] % k == 0) {
            int t = a[i] / k;
            if(m1.count(t)) d1[i] = m1[t];
            else d1[i] = 0;
        }
        m1[a[i]]++;
    }

    ll ret = 0;
    for(int i = n - 1; i >= 0; --i) {
        ll t = 1LL * a[i] * k;
        if(m2.count(t)) ret += 1LL * m2[t] * d1[i];
        m2[a[i]]++;
    }

    return ret;

}

int main() {
    rii(n, k);

    rep(i, n) {
        int x; ri(x);
        if(x == 0) zero++;
        else if(x > 0) pos.PB(x);
        else neg.PB(-x);
    }

    ll ans = 1LL * zero * (zero - 1) * (zero - 2) / 6;
    ans += solve(pos);
    ans += solve(neg);

    cout << ans << endl;

    return 0;
}