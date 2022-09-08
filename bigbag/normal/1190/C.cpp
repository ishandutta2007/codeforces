#include <bits/stdc++.h>

using namespace std;

const int max_n = 100011, inf = 1000111222;

int n, k, sum[max_n];
char s[max_n];
vector<int> v[2];

int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, s);
    sum[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
        sum[i] = sum[i - 1] + s[i] - '0';
    }
    for (int i = 0; i + k <= n; ++i) {
        int x = get_sum(0, i - 1) + get_sum(i + k, n - 1);
        if (x == 0 || x + k == n) {
            puts("tokitsukaze");
            return 0;
        }
    }
    v[0].push_back(-inf);
    v[1].push_back(-inf);
    for (int i = 0; i < n; ++i) {
        v[s[i] - '0'].push_back(i);
    }
    v[0].push_back(inf);
    v[1].push_back(inf);
    for (int i = 0; i + k <= n; ++i) {
        bool ok = false;
        for (int c1 = 0; c1 < 2; ++c1) {
            bool win2 = false;
            int mn = v[c1 ^ 1][1];
            int mx = v[c1 ^ 1][v[c1 ^ 1].size() - 2];
            //cout << i << " " << c1 << " " << mn << " " << mx << endl;
            if (mn >= i) {
                mn = *lower_bound(v[c1 ^ 1].begin(), v[c1 ^ 1].end(), i + k);
            }
            if (mx < i + k) {
                auto it = lower_bound(v[c1 ^ 1].begin(), v[c1 ^ 1].end(), i);
                --it;
                mx = *it;
            }
            if (mx - mn < k) {
                win2 = true;
            }
            //cout << i << " " << c1 << " " << mn << " " << mx << endl;
            if (!win2) {
                puts("once again");
                return 0;
            }
        }
    }
    puts("quailty");
    return 0;
}