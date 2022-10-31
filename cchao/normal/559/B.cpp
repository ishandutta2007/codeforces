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
const int maxn = 200010;
const double eps = 1e-8;
char a[maxn], b[maxn];

void go(char *s, int len) {
    if(len & 1) return ;
    len >>= 1;
    go(s, len); go(s + len, len);
    if(strncmp(s, s + len, len) > 0) {
        rep(i, len) swap(s[i], s[i + len]);
    }
}

int main() {
    rs(a); rs(b);
    int la = strlen(a), lb = strlen(b);
    go(a, la);
    go(b, lb);

    puts(strcmp(a, b) == 0 ? "YES" : "NO");
    return 0;
}