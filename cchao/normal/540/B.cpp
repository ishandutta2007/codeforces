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

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int a[1010];
vector<int> ans;
int main() {
    int n, k, p, x, y;
    riii(n, k, p); rii(x, y);
    
    int l = x;
    rep(i, k) {
        ri(a[i]);
        l -= a[i];
    }

    for(int i = k; i < n; ++i) {
        a[i] = 1;
        l--;
    }
    for(int i = k; i < n; ++i) {
        if(l > 0) {
            int t = min(l, y - a[i]);
            a[i] += t;
            l -= t;
        }
        ans.push_back(a[i]);
    }

    sort(a, a + n);
    double mid = n % 2 == 0 ? (a[n / 2] + a[n / 2 - 1]) / 2.0 : a[n / 2];

    if(l < 0 || mid < y) puts("-1");
    else {
        rep(i, n - k) printf("%d ", ans[i]);
        puts("");
    }


    return 0;
}