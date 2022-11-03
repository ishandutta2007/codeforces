#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

const int max_k = 55;
const int max_n = 111;

int k, n, m;
int s[max_k], f[max_k];
ll c1[max_k], c2[max_k], c12[max_k], c21[max_k], c22[max_k], c11[max_k];
ll x;

char s1[max_n], s2[max_n];

int main() {
    ios_base::sync_with_stdio(false);
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    cin >> k >> x >> n >> m;
    s[0] = f[0] = c1[0] = 1;
    c2[0] = c12[0] = c21[0] = c11[0] = c22[0] = 0;
    s[1] = f[1] = 2;
    c2[1] = 1;
    c1[1] = c12[1] = c21[1] = c11[1] = c22[1] = 0;
    for (int i = 2; i < k; ++i) {
        s[i] = s[i - 2];
        f[i] = f[i - 1];
        c1[i] = c1[i - 1] + c1[i - 2];
        c2[i] = c2[i - 1] + c2[i - 2];
        c12[i] = c12[i - 1] + c12[i - 2];
        c21[i] = c21[i - 1] + c21[i - 2];
        c11[i] = c11[i - 1] + c11[i - 2];
        c22[i] = c22[i - 1] + c22[i - 2];
        if (f[i - 2] == 1) {
            if (s[i - 1] == 1)
                ++c11[i];
            else
                ++c12[i];
        } else {
            if (s[i - 1] == 1)
                ++c21[i];
            else
                ++c22[i];
        }
    }
    for (int i = 0; i < n; ++i)
        s1[i] = 'X';
    s1[n] = 0;
    for (int i = 0; i < m; ++i)
        s2[i] = 'X';
    s2[m] = 0;
    for (int mask = 0; mask < (1 << 4); ++mask) {
        if (n == 1) {
            if (bit(mask, 0) || (bit(mask, 1) && bit(mask, 2)))
                continue;
        }
        if (m == 1) {
            if (bit(mask, 3) || (bit(mask, 1) && bit(mask, 2)))
                continue;
        }
        ll cx = x;
        cx -= c11[k - 1] * bit(mask, 0);
        cx -= c12[k - 1] * bit(mask, 1);
        cx -= c21[k - 1] * bit(mask, 2);
        cx -= c22[k - 1] * bit(mask, 3);
        if (cx < 0) continue;
        int len1, len2;
        int k1max, k2max;
        if (bit(mask, 0)) {
            len1 = n - 2;
        } else {
            len1 = n - bit(mask, 1) - bit(mask, 2);
        }
        if (bit(mask, 3)) {
            len2 = m - 2;
        } else {
            len2 = m - bit(mask, 1) - bit(mask, 2);
        }
        k1max = len1 / 2;
        k2max = len2 / 2;
        for (int k1 = 0; k1 <= k1max; ++k1)
            for (int k2 = 0; k2 <= k2max; ++k2)
                if (c1[k - 1] * k1 + c2[k - 1] * k2 == cx) {
                    if (bit(mask, 0)) {
                        s1[0] = 'C';
                        s1[n - 1] = 'A';
                    } 
                    if (bit(mask, 1)) {
                        s1[n - 1] = 'A';
                        s2[0] = 'C';
                    }
                    if (bit(mask, 2)) {
                        s1[0] = 'C';
                        s2[m - 1] = 'A';
                    } 
                    if (bit(mask, 3)) {
                        s2[0] = 'C';
                        s2[m - 1] = 'A';
                    }
                    for (int i = (bit(mask, 0) | bit(mask, 2)), t = 0; t < k1 && i < n - (bit(mask, 0) | bit(mask, 1)); i += 2, ++t) {
                        s1[i] = 'A';
                        s1[i + 1] = 'C';
                    }
                    for (int i = (bit(mask, 1) | bit(mask, 3)), t = 0; t < k2 && i < m - (bit(mask, 2) | bit(mask, 3)); i += 2, ++t) {
                        s2[i] = 'A';
                        s2[i + 1] = 'C';
                    }
                    cout << s1 << endl;
                    cout << s2 << endl;
                    return 0;
                }
    }
    cout << "Happy new year!" << endl;
    // 11 s1 = C...A s2 = ...
    // 12 s1 = ...A s2 = C...
    // 21 s1 = C... s2 = ...A
    // 22 s1 = ... s2 = C...A
    return 0;
}