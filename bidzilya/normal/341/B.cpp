#include <cstdio>
#include <cstring>

#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e5 + 100;

int t[4 * max_n];
int n;

int max_on_seg(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r)
        return t[v];
    int m = (tl + tr) >> 1;
    if (r <= m)
        return max_on_seg(2 * v, tl, m, l, r);
    if (l > m)
        return max_on_seg(2 * v + 1, m + 1, tr, l, r);
    return max(max_on_seg(2 * v, tl, m, l, m),
                max_on_seg(2 * v + 1, m + 1, tr, m + 1, r));
}

void update(int v, int tl, int tr, int x, int d) {
    if (tl == tr) {
        t[v] = d;
    } else {
        int m = (tl + tr) >> 1;
        if (x <= m)
            update(2 * v, tl, m, x, d);
        else
            update(2 * v + 1, m + 1, tr, x, d);
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        int d = max_on_seg(1, 1, n, 1, a) + 1;
        ans = max(ans, d);
        update(1, 1, n, a, d);
    }
    cout << ans << endl;
    return 0;
}