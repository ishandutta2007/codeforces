#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const int max_n = 3e5;

int n, k;
ll sum[max_n + 1];
ll dp[max_n + 1];
int id[max_n + 1];

int main() {
    cin >> n >> k;
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    dp[n - k + 1] = sum[n] - sum[n - k];
    id[n - k + 1] = n - k + 1;
    for (int i = n - k; i >= 1; --i) {
        dp[i] = dp[i + 1];
        id[i] = id[i + 1];
        if (sum[i + k - 1] - sum[i - 1] >= dp[i]) {
            dp[i] = sum[i + k - 1] - sum[i - 1];
            id[i] = i;
        }
    }
    ll ans = sum[2 * k];
    int id1 = 1;
    int id2 = 1 + k;
    for (int i = 1; i + k <= n - k + 1; ++i)
        if (sum[i + k - 1] - sum[i - 1] + dp[i + k] > ans) {
            ans = sum[i + k - 1] - sum[i - 1] + dp[i + k];
            id1 = i;
            id2 = id[i + k];
        }
    cout << id1 << " " << id2 << endl;
        
    return 0;
}