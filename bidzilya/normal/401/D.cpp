#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int max_n = 18;
const int max_mask = (1 << max_n);
const int max_m = 101;
const int max_d = 10000;

ll n;
int a[max_n];
int m;
int c;
ll cnt[max_mask][max_m];
int cur_max_mask;
int md[max_d];

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

int main() {
  //  freopen("input.txt", "r", stdin);
 //	freopen("output.txt", "w", stdout);

    while (cin >> n >> m) { 
        for (int i = 0; i < max_d; ++i)
            md[i] = (i % m);
        c = 0;
        while (n > 0) {
            a[c] = n % 10;
            n /= 10;
            ++c;
        }
        sort(a, a + c);
        cur_max_mask = (1 << c);
        for (int mask = 0; mask < cur_max_mask; ++mask)
            for (int i = 0; i < m; ++i)
                cnt[mask][i] = 0;
        for (int i = 0; i < c; ++i)
            if (a[i] != 0 && (i == 0 || a[i - 1] != a[i]))
                cnt[1 << i][md[a[i]]] = 1;
        for (int mask = 0; mask < cur_max_mask; ++mask)
            for (int b = 0; b < c; ++b)
                if (!bit(mask, b)) {
                    for (int i = 0; i < m; ++i)
                        cnt[mask + (1 << b)][md[i * 10 + a[b]]] += cnt[mask][i];
                    while (b + 1 < c && a[b + 1] == a[b]) ++b;
                }
        cout << cnt[cur_max_mask - 1][0] << endl;
    }
    
    return 0;
}