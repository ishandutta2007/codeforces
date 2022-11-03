#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int max_n = 1e3 + 100;
const int modulo = 1e9 + 7;

int n;
int p[max_n];
int d[max_n];

int sum(int l, int r) {
    int res = d[r];
    if (l > 0) {
        res -= d[l - 1];
        if (res < 0) res += modulo;
    }
    return res;
}

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            --p[i];
        }
        d[0] = 2;
        for (int i = 1; i < n; ++i) {
            if (p[i] == i) {
                d[i] = 2;
            } else {
                d[i] = 2 + sum(p[i], i - 1);
                if (d[i] >= modulo) d[i] -= modulo;
            }
            d[i] += d[i - 1];
            if (d[i] >= modulo) d[i] -= modulo;
        }
        cout << sum(0, n - 1) << endl;
    }
   
    return 0;
}