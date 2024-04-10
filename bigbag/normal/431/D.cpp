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

const int max_n = 111;
const long long inf = 1111111111111111111LL;

long long m, l, r, dp[max_n][max_n][2];
int k;

void get_dp() {
    dp[1][1][1] = 1;
    for (int len = 2; len < max_n; ++len) {
        for (int i = 0; i < 2; ++i) {
            for (int x = 1; x <= len; ++x) {
                dp[len][x][i] = dp[len - 1][x - i][0] + dp[len - 1][x - i][1];
            }
        }
    }
}

long long fun(long long r) {
    long long res = 0;
    if (k == 1 && r >= 2) {
        ++res;
    }
    vector<int> v;
    long long Q = r;
    while (Q) {
        v.push_back(Q % 2);
        Q /= 2;
    }
    reverse(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        res += dp[i][k][1];
    }
    int cnt = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == 1) {
            res += dp[v.size() - i][k - cnt][0];
        }
        cnt += v[i];
        if (cnt > k) {
            break;
        }
    }
    if (cnt == k) {
        ++res;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> k;
    get_dp();
    l = 0;
    r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (fun(2 * mid - 1) < m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}