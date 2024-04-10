#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;
const int max_b = 62;

mt19937 gen(time(NULL));
int n, a[max_n], f[max_n], last[max_n];
vector<int> all[max_b];
long long m[max_n];

bool get_bit(long long mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%I64d", &a[i], &m[i]);
        sum += a[i];
        for (int j = 0; j < max_b; ++j) {
            if (get_bit(m[i], j)) {
                last[i] = j;
            }
        }
        all[last[i]].push_back(i);
    }
    if (sum < 0) {
        sum *= -1;
        for (int i = 0; i < n; ++i) {
            a[i] *= -1;
        }
    }
    long long mask = 0;
    for (int pos = 0; pos < 62; ++pos) {
        long long s1 = 0, s2 = 0;
        for (int id : all[pos]) {
            if (f[id]) {
                s1 += a[id];
            } else {
                s2 += a[id];
            }
        }
        if (s1 < s2) {
            mask ^= (1LL << pos);
            for (int i = 0; i < n; ++i) {
                f[i] ^= get_bit(m[i], pos);
            }
        }
    }
    printf("%I64d\n", mask);
    return 0;
}