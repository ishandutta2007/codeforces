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
const int maxn = 4010;
const double eps = 1e-8;

int N, K, w[maxn][maxn]={{}}, d[maxn]={}, c[maxn]={};
int main() {
    rii(N, K);
    repe(i, 1, N) repe(j, 1, N) {
        char c;
        while(isspace(c = getchar())) ;
        w[i][j] = c - '0';
        if(i < j) w[i][j] = 0;
        w[i][j] += w[i][j-1] + w[i-1][j] - w[i-1][j-1];
    }
    c[N+1] = N;
    repe(k, 1, K) {
        for(int n = N; n; --n) {
            if(k == 1) {
                d[n] = w[n][n];
                c[n] = 1;
            }
            else if(n <= k) {
                d[n] = 0;
                c[n] = n;
            }
            else {
                int beg = max(c[n], 1), end = min(c[n+1], n);
                d[n] = INT_MAX;
                repe(i, beg, end) {
                    int t = d[i - 1] + w[n][n] - w[n][i-1];
                    if(t < d[n]) {
                        d[n] = t;
                        c[n] = i;
                    }
                }
                // printf("n %d k %d: %d -- %d\n", n, k, beg, end);
            }
            // printf("n %d k %d c %d r %d\n", n, k, c[n], d[n]);
        }
    }
    pi(d[N]);
    return 0;
}