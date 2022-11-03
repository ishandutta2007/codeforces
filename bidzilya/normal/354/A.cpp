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

const int max_int = (1LL << 31) - 1;

const int max_n = 1e5 + 100;

int l, r, ql, qr, n;
int w[max_n];
int ls[max_n], rs[max_n];

int main() {
    cin >> n >> l >> r >> ql >> qr;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i)
        ls[i] = ls[i - 1] + w[i];
    for (int i = n; i >= 1; --i)
        rs[i] = rs[i + 1] + w[i];
    int ans = max_int;
    for (int i = 0; i <= n; ++i) {
        int cans = ls[i] * l + rs[i + 1] * r;
        int c1 = i;
        int c2 = n - i;
        if (c1 < c2) {
            c2 -= c1;
            if (c2) --c2;
            cans += c2 * qr;
        } else if (c1 > c2) {
            c1 -= c2;
            if (c1) --c1;
            cans += c1 * ql;
        }
        ans = min(ans, cans);
    }
    cout << ans << endl;
    return 0;
}