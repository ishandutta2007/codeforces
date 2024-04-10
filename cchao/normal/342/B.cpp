#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define ri(a) scanf("%d", &a)
#define rii(a, b) scanf("%d%d", &a, &b)
#define riii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define rs(s) scanf("%s", s)
#define pi(n) printf("%d\n", n)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _ == n - 1 ? '\n' : ' ')
#define ria(a, n) rep(_, n) scanf("%d", &a[_])
#define Ttimes int T; ri(T); for(int ks = 1; ks <= T; ++ks)
#define PB push_back
#define MP make_pair

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 100010;
const double eps = 1e-8;

int ti[maxn], l[maxn], r[maxn];
int main() {
    int n, m; rii(n, m);
    int s, t; rii(s, t);
    rep(i, m) riii(ti[i], l[i], r[i]);

    int current = 1, idx = 0;
    int dir = s < t ? 1 : -1;
    for( ;s != t; current++) {
        if(idx < m && current == ti[idx]) {
            if((l[idx] <= s && s <= r[idx]) || (l[idx] <= s + dir && s + dir <= r[idx]))  {
                putchar('X');
                idx++;
                continue;
            }
            idx++;
        }
        s += dir;
        putchar(dir == 1 ? 'R' : 'L');
    }
    putchar('\n');

    return 0;
}