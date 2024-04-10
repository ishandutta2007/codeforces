#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 5e3 + 100;

int n;
int ans = 0;
int a[max_n];
int dp[max_n][max_n], f[max_n][max_n];

int sum(int l, int r) {
    return a[r] - a[l - 1];
}

int fnc(int l, int sm) {
    int lb = 1, rb = n - l + 1, ans = 0;
    while (lb <= rb) {
        int mb = (lb + rb) >> 1;
        if (sum(l, l + mb - 1) >= sm) {
            ans = mb;
            rb = mb - 1;
        } else {
            lb = mb + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int ans = n;
    f[1][1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j <= i - 1; ++j)
            if (f[i - 1][j]) {
                if (!f[i][j + 1] || dp[i - 1][j] + 1 < dp[i][j + 1]) {
                    dp[i][j + 1] = dp[i - 1][j] + 1;
                    f[i][j + 1] = 1;
                }
                int cnt = fnc(i, sum(i - j, i - 1));
                if (cnt && (!f[i + cnt - 1][cnt] || dp[i - 1][j] + cnt - 1 < dp[i + cnt - 1][cnt])) {
                    f[i + cnt - 1][cnt] = 1;
                    dp[i + cnt - 1][cnt] = dp[i - 1][j] + cnt - 1;
                }
            }
    for (int i = 1; i <= n; ++i)
        if (f[n][i])
            ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}