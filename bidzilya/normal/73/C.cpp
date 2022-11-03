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

const int max_n = 1e2 + 10;

int k, n;
string s;
int c[26][26];
int dp[max_n][max_n][26], f[max_n][max_n][26];

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> s >> k;
    for (cin >> n; n; --n) {
        char x, y;
        int tc;
        cin >> x >> y >> tc;
        c[x - 'a'][y - 'a'] = tc;
    }
    n = s.length();
    for (int i = 0; i < 26; ++i) {
        int dk = ((i + 'a') != s[0]);
        dp[0][dk][i] = 0;
        f[0][dk][i] = 1;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int ch = 0; ch < 26; ++ch)
                if (f[i - 1][j][ch])
                    for (int nch = 0; nch < 26; ++nch) {
                        int dk = ((nch + 'a') != s[i]);
                        if (!f[i][j + dk][nch] || dp[i][j + dk][nch] < dp[i - 1][j][ch] + c[ch][nch]) {
                            f[i][j + dk][nch] = 1;
                            dp[i][j + dk][nch] = dp[i - 1][j][ch] + c[ch][nch];
                        }
                    }                
    int ans = -1e8;
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j < 26; ++j)
            if (f[n - 1][i][j])
                ans = max(ans, dp[n - 1][i][j]);
    cout << ans << endl;
    return 0;
}