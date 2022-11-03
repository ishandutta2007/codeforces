#include <cstdio>
#include <cstring>
#include <cmath>

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

ull d[40][40];
int f[40][40];

ull go(int n, int h) {
    if (f[n][h])
        return d[n][h];
    f[n][h] = 1;
    if (n == 0 && h == 0) {
        d[n][h] = 1;
        return 1;
    }
    if (n == 0 && h != 0) {
        d[n][h] = 0;
        return 0;
    }
    for (int t = 1; t <= n; ++t)
        for (int h1 = 0; h1 <= t - 1; ++h1)
            for (int h2 = 0; h2 <= n - t; ++h2) {
                if (max(h1 + 1, h2 + 1) != h) continue;
                d[n][h] += go(t - 1, h1) * go(n - t, h2);
            }
    return d[n][h];
}

int main() {
    ios_base::sync_with_stdio(false); 
    int n, h;
    cin >> n >> h;
    ull ans = 0;
    for (int h1 = h; h1 <= n; ++h1)
        ans += go(n, h1);
    cout << ans << endl;
    return 0;
}