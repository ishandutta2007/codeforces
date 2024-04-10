#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_a = 1e6;
const int modulo = 1e9 + 7;

int t[4 * max_a];

void seg_set(int v, int tl, int tr, int x, int d) {
    if (tl == tr) {
        t[v] = d;
    } else {
        int m = (tl + tr) >> 1;
        if (x <= m)
            seg_set(2 * v, tl, m, x, d);
        else
            seg_set(2 * v + 1, m + 1, tr, x, d);
        t[v] = (t[2 * v] + t[2 * v + 1]) % modulo;
    }
}

int seg_sum(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) 
        return t[v];
    else {
        int m = (tl + tr) >> 1;
        if (r <= m)
            return seg_sum(2 * v, tl, m, l, r);
        else if (l > m)
            return seg_sum(2 * v + 1, m + 1, tr, l, r);
        else
            return (seg_sum(2 * v, tl, m, l, m) + seg_sum(2 * v + 1, m + 1, tr, m + 1, r)) % modulo;
    }
}

int n;

int main() { 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        seg_set(1, 1, max_a, a, (1LL * a * seg_sum(1, 1, max_a, 1, a) + a) % modulo);
    }
    cout << seg_sum(1, 1, max_a, 1, max_a) << endl;
    return 0;
}