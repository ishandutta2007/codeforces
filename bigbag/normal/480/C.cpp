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

const int max_n = 5055, inf = 1000000007;

int n, a, b, k;
long long sum[max_n], dp[max_n][max_n];

long long get_sum(int l, int r) {
    if (l > r) return 0;
    return ((sum[r] - sum[l - 1]) + inf) % inf;
}

void get_all_sum(int poz) {
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = (sum[i - 1] + dp[poz][i]) % inf;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> k;
    for (int i = 1; i <= n; ++i) {
        if (i != b) dp[1][i] = 1;
    }
    //dp[1][a] = 1;
    ++k;
    get_all_sum(1);
    for (int len = 2; len <= k; ++len) {
        for (int i = 1; i <= n; ++i) {
            if (i < b) {
                int q = b - i;
                int l = max(1, i - q + 1);
                dp[len][i] = (get_sum(l, i - 1) + get_sum(i + 1, b - 1)) % inf;
                //cout << i << " - " << l << " " << i - 1 << "   " << i + 1 << " " << b - 1<< endl;
            } else if (i > b) {
                int q = i - b;
                int r = min(n, i + q - 1);
                dp[len][i] = (get_sum(b + 1, i - 1) + get_sum(i + 1, r)) % inf;
            } else {
                dp[len][i] = 0;
            }
        }
        get_all_sum(len);
    }
    /*for (int len = 1; len <= k; ++len) {
        cout << len << " : ";
        for (int i = 1; i <= n; ++i) {
            cout << dp[len][i] << " ";
        }
        cout << endl;
    }*/
    cout << dp[k][a] << endl;
    return 0;
}