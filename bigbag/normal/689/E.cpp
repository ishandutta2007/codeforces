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

const int max_n = 222222, mod = 1000000007;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int n, k, f[max_n], rf[max_n];
vector<pair<int, int> > q;

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[n - k]) % mod;
    res = (1LL * res * rf[k]) % mod;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        q.push_back(make_pair(l, 1));
        q.push_back(make_pair(r + 1, -1));
    }
    sort(q.begin(), q.end());
    int ans = 0, cnt = 0;
    for (int i = 0; i + 1 < q.size(); ++i) {
        cnt += q[i].second;
        ans += (1LL * get_c(cnt, k) * (q[i + 1].first - q[i].first)) % mod;
        /*if ((1LL * get_c(cnt, k) * (q[i + 1].first - q[i].first)) % mod) {
            cout << q[i].first << " " << q[i].second << " : " << cnt << "  += " << (1LL * get_c(cnt, k) * (q[i + 1].first - q[i].first)) % mod << endl;
        }*/
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}