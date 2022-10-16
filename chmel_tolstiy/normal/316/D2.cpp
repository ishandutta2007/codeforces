#include <cstdio>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set< vector<int> > s;
set< pair< vector<int>, vector<int> > > w;

void gen(vector<int> v, vector<int> o) {
    if (w.count(make_pair(v, o))) return;
    w.insert(make_pair(v, o));
    s.insert(v);
    for (int i = 0; i < v.size(); ++i) for (int j = i + 1; j < v.size(); ++j) if (o[i] && o[j]) {
        o[i]--; o[j]--;
        swap(v[i], v[j]);
        gen(v, o);
        o[i]++; o[j]++;
        swap(v[i], v[j]);
    }
}

const int MOD = 1000000007;

int memo[512][512];
long long C[512][512];
long long F[512];

int f(int l, int r) {
    if (r < 0) return 0;
    if (l <= 0) return F[r];
    if (memo[l][r] >= 0) return memo[l][r];

    long long res = 0;
    for (int k = 0; k <= r; ++k) {
        long long M = F[k] * C[r][k] % MOD;
        long long D = (f(l - 1, r - k) + 1LL * f(l - 2, r - k) * (l - 1) * (k + 1)) % MOD;
        res += M * D % MOD;
    }

    return memo[l][r] = res % MOD;
}

int main() {
    memset(memo, -1, sizeof memo);
    C[0][0] = 1;
    F[0] = 1;
    for (int i = 1; i < 512; ++i) {
        C[i][0] = 1;
        F[i] = 1LL * i * F[i-1] % MOD;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }

    int n;
    cin >> n;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ones += x == 1;
        twos += x == 2;
    }
/*
    for (int i = 0; i < 10; i++) {
        cout << "i = " << i << endl;
        for (int j = 0; j < 10; j++) {
            printf("%7d ", f(i, j));
        }
        cout << endl;
    }
*/
    cout << f(ones, twos) << endl;

    return 0;
}