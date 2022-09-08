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

const int max_n = 111111, mod = 1000000007;

int n, m, s[max_n], t[max_n], dp[max_n], f[max_n];
vector<pair<int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    v.push_back(make_pair(0, 1));
    for (int i = 2; i <= m + 1; ++i) {
        scanf("%d%d", &s[i], &t[i]);
        v.push_back(make_pair(s[i], -i));
        v.push_back(make_pair(t[i], i));
    }
    if (m == 0) {
        printf("0\n");
        return 0;
    }
    sort(v.begin(), v.end());
    long long cnt = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        //cout << v[i].first << " " << v[i].second << "   cnt = " << cnt << endl;
        if (v[i].second > 0) {
            long long p = 0;
            while (i > 0 && v[i - 1].second > 0 && v[i - 1].first == v[i].first) {
                dp[v[i].second] = cnt;
                p += cnt;
                if (v[i].first == n) {
                    ++dp[v[i].second];
                    ++p;
                }
                p %= mod;
                --i;
            }
            dp[v[i].second] = cnt;
            p += cnt;
            if (v[i].first == n) {
                ++dp[v[i].second];
                ++p;
            }
            p %= mod;
            cnt += p;
            cnt %= mod;
        } else {
            cnt = ((cnt - dp[-v[i].second]) % mod + mod) % mod;
        }
    }
    printf("%d\n", dp[1]);
    return 0;
}