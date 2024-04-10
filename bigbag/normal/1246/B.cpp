#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, k, a[max_n];
long long ans;
map<vector<pair<int, int>>, int> cnt;

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                ++cnt;
            }
            cnt %= k;
            if (cnt) {
                res.push_back({i, cnt});
            }
        }
    }
    if (x > 1) {
        res.push_back({x, 1});
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        vector<pair<int, int>> v = factorize(a[i]);
        for (int j = 0; j < v.size(); ++j) {
            v[j].second = k - v[j].second;
        }
        auto it = cnt.find(v);
        if (it != cnt.end()) {
            ans += it->second;
        }
        for (int j = 0; j < v.size(); ++j) {
            v[j].second = k - v[j].second;
        }
        ++cnt[v];
    }
    printf("%I64d\n", ans);
    return 0;
}