#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 2010;

unordered_map<long long, long long> f;

long long dp(long long N) {
    if (N == 1 || N == 0) return f[N] = 1; 
    if (f[N] > 0) return f[N];
    return f[N] = dp(N / 2) * 2 + 1;
}

long long count(long long N, long long L, long long R) {
    if (R < L) return 0;
    if (N == 0) return 0;
    if (N == 1) return 1;
    long long ans = 0;
    ans += count(N / 2, L, min(f[N / 2], R));
    if (L <= f[N / 2] + 1 && f[N / 2] + 1 <= R) ans += N % 2;
    ans += count(N / 2, max(1LL, L - f[N / 2] - 1), R - f[N / 2] - 1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long N, L, R;
    cin >> N >> L >> R;
    dp(N);
    cout << count(N, L, R) << endl;
    return 0;
}