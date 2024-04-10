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

const int max_n = 55, inf = 111111111;

int n, m, k, napr, dp[max_n][max_n][2], cnt[222];
string q;
vector<int> v1, v2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    getline(cin, q);
    if (q == "to head") {
        napr = 0;
    } else {
        napr = 1;
    }
    cin >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int f = 0; f < 2; ++f) {
                if (f == 0) {
                    if (i == j) {
                        dp[i][j][f] = 0;
                    } else {
                        if (i < j) {
                            dp[i][j][f] = j - 1;
                        } else {
                            dp[i][j][f] = j + n - 2;
                        }
                    }
                } else {
                    if (i == j) {
                        dp[i][j][f] = 0;
                    } else {
                        if (i > j) {
                            dp[i][j][f] = n - j;
                        } else {
                            dp[i][j][f] = 2 * n - j - 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < q.length(); ++i) {
        if (q[i] == '0') {
            v1.push_back(i);
        } else {
            v2.push_back(i);
        }
    }
    for (int i = 0; i < q.length(); ++i) {
        if (q[i] == '0') {
            int poz = *lower_bound(v2.begin(), v2.end(), i);
            int cnt = dp[m][k][napr];
            //cout << i << ' ' << cnt << "   " << m << ' ' << k << endl;
            if (cnt <= poz - i) {
                cout << "Controller " << i + dp[m][k][napr] << endl;
                return 0;
            }
            for (int j = 0; j < poz - i; ++j) {
                if (napr == 0) {
                    --k;
                    if (k == 1) {
                        napr = 1;
                    }
                } else {
                    ++k;
                    if (k == n) {
                        napr = 0;
                    }
                }
            }
            i = poz - 1;
        } else {
            for (int j = 0; j < 1; ++j) {
                if (napr == 0) {
                    --k;
                    if (k == 1) {
                        napr = 1;
                    }
                } else {
                    ++k;
                    if (k == n) {
                        napr = 0;
                    }
                }
            }
            int max_dp = -1;
            for (int j = 1; j <= n; ++j) {
                if (max_dp < dp[j][k][napr]) {
                    max_dp = dp[j][k][napr];
                    m = j;
                }
            }
        }
    }
    cout << "Stowaway" << endl;
    return 0;
}