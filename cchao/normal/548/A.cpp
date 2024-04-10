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

bool f(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main() {
    string s; cin >> s;
    int k; cin >> k;
    if(s.size() % k) {
        puts("NO");
    }
    else {
        int n = s.size() / k;
        bool fg = false;
        for(int i = 0; i < s.size(); i += n)
            if(!f(s.substr(i, n))) {
                fg = true;
                break;
            }
        puts(fg ? "NO" : "YES");
    }
    return 0;
}