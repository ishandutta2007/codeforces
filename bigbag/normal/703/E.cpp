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

const int max_n = 1011;
const int max_p = 1000111;

int used[max_p];
vector<int> pw;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            pw.push_back(i);
            if (1LL * i * i < max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int n, b[max_n], c[max_n];
long long k;
vector<pair<long long, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    scanf("%d%I64d", &n, &k);
    if (k == 1) {
        pair<long long, int> ans = make_pair(1111111111111111111LL, 1);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &k);
            ans = min(ans, make_pair(k, i + 1));
        }
        printf("1\n%d\n", ans.second);
        return 0;
    }
    for (int i = 0; i < pw.size(); ++i) {
        int cnt = 0;
        while (k % pw[i] == 0) {
            k /= pw[i];
            ++cnt;
        }
        if (cnt) {
            v.push_back(make_pair(pw[i], cnt));
        }
    }
    if (k > 1) {
        v.push_back(make_pair(k, 1));
    }
    int mx = 1;
    for (int i = 0; i < v.size(); ++i) {
        mx *= (1 + v[i].second);
        //cout << v[i].first << " " << v[i].second << endl;
    }
    int p[max_n][mx];
    pair<int, long long> dp[max_n][mx], np;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < mx; ++j) {
            dp[i][j] = make_pair(-1, -1LL);
        }
    }
    dp[0][0] = make_pair(0, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &k);
        long long K = k;
        for (int j = 0; j < v.size(); ++j) {
            b[j] = 0;
            while (k % v[j].first == 0) {
                ++b[j];
                k /= v[j].first;
            }
        }
        for (int mask = 0; mask < mx; ++mask) {
            if (dp[i][mask] == make_pair(-1, -1LL)) {
                continue;
            }
            //cout << i << " " << mask << " " << dp[i][mask].first << endl;
            int q = mask, to = 0;
            for (int j = 0; j < v.size(); ++j) {
                c[j] = min(q % (v[j].second + 1) + b[j], v[j].second);
                q /= (v[j].second + 1);
            }
            for (int j = v.size() - 1; j >= 0; --j) {
                to = to * (v[j].second + 1) + c[j];
            }
            if (dp[i + 1][mask] == make_pair(-1, -1LL) || dp[i + 1][mask] > dp[i][mask]) {
                dp[i + 1][mask] = dp[i][mask];
                p[i + 1][mask] = mask;
            }
            np = dp[i][mask];
            ++np.first;
            np.second += K;
            if (dp[i + 1][to] == make_pair(-1, -1LL) || dp[i + 1][to] > np) {
                dp[i + 1][to] = np;
                p[i + 1][to] = mask;
            }
        }
    }
    pair<pair<int, long long>, int> ans = make_pair(make_pair(11111111, 1111111111111111111LL), 1);
    for (int i = 1; i <= n; ++i) {
        //cout << i << " : " << dp[i][mx - 1].first << " " << dp[i][mx - 1].second << endl;
        if (dp[i][mx - 1] != make_pair(-1, -1LL)) {
            ans = min(ans, make_pair(dp[i][mx - 1], i));
        }
    }
    if (ans == make_pair(make_pair(11111111, 1111111111111111111LL), 1)) {
        printf("-1\n");
        return 0;
    }
    //cout << ans.first.first << " " << ans.first.second << endl;
    int poz = ans.second;
    vector<int> q;
    --mx;
    while (dp[poz][mx].first) {
        int pp = p[poz][mx];
        if (pp != mx) {
            q.push_back(poz);
        }
        mx = pp;
        --poz;
    }
    reverse(q.begin(), q.end());
    printf("%d\n", q.size());
    for (int i = 0; i < q.size(); ++i) {
        printf("%d ", q[i]);
    }
    printf("\n");
    return 0;
}