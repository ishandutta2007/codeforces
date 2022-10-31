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

ll c[100010] = {};

int main() {
    int n; ri(n); rep(i, n) {
        int t; ri(t); c[t] += t;
    }
    for(int i = 2; i < 100010; ++i)
        c[i] = max(c[i-1], c[i-2] + c[i]);
    printf("%I64d\n", c[100009]);
    return 0;
}