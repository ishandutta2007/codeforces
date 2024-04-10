#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;

#define pb push_back

#define X first
#define Y second

#define MOD 1000000007
#define N 1000005
#define K 1005

int r[N], f[N], g[N];
int ans, s[K];

int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return 1LL * f[n] * g[n - m] % MOD * g[m] % MOD;
}

int main() {

    int i, n, c;

    for (r[1] = 1, i = 2; i < N; i++) {
        r[i] = -1LL * r[MOD % i] * (MOD / i) % MOD;
        if (r[i] < 0) r[i] += MOD;
    }

    for (f[0] = i = 1; i < N; i++) f[i] = 1LL * f[i - 1] * i % MOD;
    for (g[0] = i = 1; i < N; i++) g[i] = 1LL * g[i - 1] * r[i] % MOD;

    scanf("%d", &n);
    for (ans = i = 1; i <= n; i++) {
        scanf("%d", &c);
        s[i] = s[i - 1] + c;
        ans = 1LL * C(s[i] - 1, c - 1) * ans % MOD;
    }

    printf("%d\n", ans);

    return 0;
}