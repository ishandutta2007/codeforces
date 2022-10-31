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

int main() {
    string s; cin >> s;

    int mx = 1;
    for(auto c: s) mx = max(mx, 0 + (c - '0'));
    vector<int> a(mx, 0);
    for(auto c: s) {
        int t = c - '0';
        rep(i, mx) a[i] *= 10;
        rep(i, t) a[i]++;
    }

    printf("%d\n", mx);
    rep(i, mx) printf("%d ", a[i]);
    puts("");

    return 0;
}