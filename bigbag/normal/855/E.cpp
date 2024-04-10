#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 65, max_b = 11, inf = 1011111111;

int q;
long long dp[max_b][max_n][1 << max_b];
long long good[max_b][max_n][1 << max_b];

void prec() {
    for (int b = 2; b <= 10; ++b) {
        dp[b][0][0] = 1;
        for (int len = 1; len < max_n; ++len) {
            for (int mask = 0; mask < (1 << b); ++mask) {
                for (int last = 0; last < b; ++last) {
                    dp[b][len][mask] += dp[b][len - 1][mask ^ (1 << last)];
                    if (last) {
                        good[b][len][mask] += dp[b][len - 1][mask ^ (1 << last)];
                    }
                }
            }
        }
    }
}

long long solve(int b, long long r) {
    vector<int> v;
    long long x = r;
    while (x) {
        v.push_back(x % b);
        x /= b;
    }
    reverse(v.begin(), v.end());
    long long res = 0;
    for (int i = 1; i < v.size(); ++i) {
        res += good[b][i][0];
    }
    int mask = 0;
    for (int i = 0; i < v.size(); ++i) {
        int st = 0;
        if (i == 0) {
            st = 1;
        }
        int last = v[i];
        if (i + 1 == v.size()) {
            ++last;
        }
        for (int j = st; j < last; ++j) {
            res += dp[b][v.size() - i - 1][mask ^ (1 << j)];
        }
        mask ^= (1 << v[i]);
    }
    return res;
}

long long solve(int b, long long l, long long r) {
    if (l == 1) {
        return solve(b, r);
    }
    return solve(b, r) - solve(b, l - 1);
}

long long triv(int b, long long l, long long r) {
    long long res = 0;
    for (auto i = l; i <= r; ++i) {
        auto x = i;
        int mask = 0;
        while (x) {
            mask ^= (1 << (x % b));
            x /= b;
        }
        if (mask == 0) {
            ++res;
            cout << i << endl;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    prec();
    scanf("%d", &q);
    while (q--) {
        int b;
        long long l, r;
        scanf("%d%I64d%I64d", &b, &l, &r);
        printf("%I64d\n", solve(b, l, r));
        //printf("%I64d\n", r - l + 1);
        //printf("%I64d\n", triv(b, l, r));
    }
    return 0;
}