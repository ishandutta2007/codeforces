#include <cstdio>
#include <cstring>

#include <iostream>
#include <fstream>
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

const int max_n = 2e3 + 100;

string s1, s2;
int dp[max_n][max_n];
int ans, n, m;

int main() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    ans = m;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = j;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (s1[i] != s2[j]));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            ans = min(ans, dp[i][j] + m - j);
    cout << ans << endl;
    return 0;
}