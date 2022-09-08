#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int n, k, a[max_n], pos[max_n];
int ans = 1;
long long sum = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        pos[a[i]] = i;
    }
    vector<int> v;
    for (int i = n; i > n - k; --i) {
        sum += i;
        v.push_back(pos[i - 1]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < v.size(); ++i) {
        ans = 1LL * ans * (v[i + 1] - v[i]) % mod;
    }
    printf("%I64d %d\n", sum, ans);
    return 0;
}