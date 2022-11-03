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

const int max_n = 3e3 + 100;

string s;
int n;
int dp[max_n][max_n];
pair<int, int> pr[max_n][max_n];

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> s;
    n = s.length();
    if (n > 26 * 99) {
        int c[26];
        for (int i = 0; i < 26; ++i)
            c[i] = 0;
        for (int i = 0; i < n; ++i)
            ++c[s[i] - 'a'];
        for (int i = 0; i < 26; ++i) 
            if (c[i] >= 100) {
                for (int j = 0; j < 100; ++j)
                    cout << (char)(i + 'a');
                cout << endl;
                return 0;
            }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        pr[i][i].first = i + 1;
        pr[i][i].second = i - 1;
    }
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len <= n; ++i) {
            dp[i][i + len - 1] = 0;
            if (s[i] == s[i + len - 1]) {
                dp[i][i + len - 1] = 2;
                if (len > 2)
                    dp[i][i + len - 1] += dp[i + 1][i + len - 2];
                pr[i][i + len - 1].first = i + 1;
                pr[i][i + len - 1].second = i + len - 2;
            }
            if (dp[i + 1][i + len - 1] > dp[i][i + len - 1]) {
                dp[i][i + len - 1] = dp[i + 1][i + len - 1];
                pr[i][i + len - 1].first = i + 1;
                pr[i][i + len - 1].second = i + len - 1;
            }
            if (dp[i][i + len - 2] > dp[i][i + len - 1]) {
                dp[i][i + len - 1] = dp[i][i + len - 2];
                pr[i][i + len - 1].first = i;
                pr[i][i + len - 1].second = i + len - 2;
            }
        }
    int mx = 0, ki, kj;
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            mx = max(mx, dp[i][j]);
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (dp[i][j] == mx) {
                ki = i;
                kj = j;
                break;
            }
    string s2 = "", s1 = "";
    while (ki <= kj) {
        int i1 = pr[ki][kj].first;
        int j1 = pr[ki][kj].second;
        if (i1 != ki && j1 != kj) {
            s1 += s[ki];
            if (ki != kj)
                s2 += s[kj];
        }
        ki = i1;
        kj = j1;
    }
    reverse(s2.begin(), s2.end());
    s = s1 + s2;
    if (mx >= 100) {
        for (int i = 0; i < 50; ++i)
            cout << s[i];
        for (int i = s.length() - 50; i < (int) s.length(); ++i)
            cout << s[i];
        cout << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}