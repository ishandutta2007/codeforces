#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int nn = 1 << 20;

inline int prev(int x) { return x & (x-1); }
inline int next(int x) { return x * 2 - (x & (x-1)); }

int S[nn];
int a[nn];
int b[nn];
int p[nn];

int set(int p, int v) {
    while (p) {
        S[p] = max(S[p], v);
        p = prev(p);
    }
}

int get_max(int p) {
    int res = 0;
    while (p < nn) {
        res = max(res, S[p]);
        p = next(p);
    }
    return res;
}

void solve() {
    int res = 1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
        p[b[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        int pos = p[a[i]] + 1;
        int cur = get_max(pos) + 1;
        set(pos, cur);
        res = max(res, cur);
    }
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}