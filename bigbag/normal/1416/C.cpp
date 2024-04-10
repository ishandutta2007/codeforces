#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333;
const int max_b = 30;

int n, a[max_n], na[max_n];
bool is_start[max_n];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    long long tot_inv = 0;
    for (int b = max_b - 1; b >= 0; --b) {
        long long tot = 0, inv = 0;
        for (int l = 0; l < n; ) {
            int r = l + 1;
            while (r < n && !is_start[r]) {
                ++r;
            }
            int c1 = 0;
            for (int i = l; i < r; ++i) {
                if (get_bit(a[i], b)) {
                    ++c1;
                } else {
                    inv += c1;
                }
            }
            tot += 1LL * c1 * (r - l - c1);
            l = r;
        }
        if (inv > tot - inv) {
            inv = tot - inv;
            ans += 1 << b;
            for (int i = 0; i < n; ++i) {
                a[i] ^= (1 << b);
            }
        }
        tot_inv += inv;
        for (int l = 0; l < n; ) {
            int r = l + 1;
            while (r < n && !is_start[r]) {
                ++r;
            }
            int pos = l;
            for (int i = l; i < r; ++i) {
                if (!get_bit(a[i], b)) {
                    na[pos++] = a[i];
                }
            }
            is_start[pos] = 1;
            for (int i = l; i < r; ++i) {
                if (get_bit(a[i], b)) {
                    na[pos++] = a[i];
                }
            }
            is_start[pos] = 1;
            l = r;
        }
        copy(na, na + n, a);
    }
    cout << tot_inv << " " << ans << "\n";
    return 0;
}