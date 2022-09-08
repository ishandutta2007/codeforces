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

const int max_n = 2222, max_h = 211111, inf = 1000000007;

int h, w, n;
long long dp[max_n], f[max_h], rf[max_h];
vector<pair<int, int> > v;

long long power(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((a * a) % inf, b / 2);
    }
    return (a * power(a, b - 1)) % inf;
}

long long get_c(int n, int k) {
    return (((f[n] * rf[k]) % inf) * rf[n - k]) % inf;
}

long long cnt(int x, int y, int x2, int y2) {
    return get_c(x2 - x + y2 - y, x2 - x);
}

int main() {
    //cout << power(2, 100) << endl;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    f[0] = 1;
    for (int i = 1; i < max_h; ++i) {
        f[i] = (f[i - 1] * i) % inf;
    }
    for (int i = 0; i < max_h; ++i) {
        rf[i] = power(f[i], inf - 2);
        //if (i < 10) cout << rf[i] << endl;
    }
    cin >> h >> w >> n;
    v.push_back(make_pair(1, 1));
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    dp[0] = cnt(v[0].first, v[0].second, h, w);
    for (int i = 1; i < v.size(); ++i) {
        //cout << v[i].first << " " << v[i].second << " : ";
        for (int j = 0; j < i; ++j) {
            if (v[i].first <= v[j].first && v[i].second <= v[j].second) {
                dp[i] += 1LL * dp[j] * cnt(v[i].first, v[i].second, v[j].first, v[j].second);
                dp[i] %= inf;
            }
        }
        dp[i] = cnt(v[i].first, v[i].second, h, w) - dp[i];
        if (dp[i] < 0) {
            dp[i] += inf;
        }
        //cout << dp[i] << endl;
    }
    cout << dp[v.size() - 1] << endl;
    return 0;
}