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

const int max_n = 30033, inf = 1111111111;

int n, d, a[max_n], dp[max_n][907];
vector<int> v[max_n];
map<pair<int, int>, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    if (d > 550) {
        v[d].push_back(d);
        m[make_pair(d, d)] = a[d];
        int ans = 0;
        for (int i = 0; i < max_n; ++i) {
            for (int j = 0; j < v[i].size(); ++j) {
               // if (rand() % 1000 == 0) cout << i << endl;
                pair<int, int> p = make_pair(i, v[i][j]), p2;
                int sum = m[p];
                //if (rand() % 1000 ==0) cout << p.first << " " << p.second << "  " << sum << endl;
                //if (p.first > 100) break;
                ans = max(ans, sum);
                if (p.second > 1 && p.first + p.second - 1 < max_n) {
                    p2 = make_pair(p.first + p.second - 1, p.second - 1);
                    if (!m.count(p2)) {
                        m[p2] = sum + a[p2.first];
                        v[p2.first].push_back(p.second - 1);
                    } else if (m[p2] < sum + a[p2.first]) {
                        m[p2] = sum + a[p2.first];
                    }
                }
                if (p.first + p.second + 1 < max_n) {
                    p2 = make_pair(p.first + p.second + 1, p.second + 1);
                    if (!m.count(p2)) {
                        m[p2] = sum + a[p2.first];
                        v[p2.first].push_back(p.second + 1);
                    } else if (m[p2] < sum + a[p2.first]) {
                        m[p2] = sum + a[p2.first];
                    }
                }
                if (p.first + p.second  < max_n) {
                    p2 = make_pair(p.first + p.second, p.second);
                    if (!m.count(p2)) {
                        m[p2] = sum + a[p2.first];
                        v[p2.first].push_back(p.second);
                    } else if (m[p2] < sum + a[p2.first]) {
                        m[p2] = sum + a[p2.first];
                    }
                }
            }
        }
        cout << ans << endl;
    } else {
        for (int i = max_n - 1; i >= d; --i) {
            for (int k = 1; k < 900; ++k) {
                dp[i][k] = a[i];
                int x = 0;
                if (k > 1 && i + k - 1 < max_n) x = max(x, dp[i + k - 1][k - 1]);
                if (i + k + 1 < max_n) x = max(x, dp[i + k + 1][k + 1]);
                if (i + k < max_n) x = max(x, dp[i + k][k]);
                dp[i][k] += x;
            }
        }
        cout << dp[d][d] << endl;
    }
    return 0;
}