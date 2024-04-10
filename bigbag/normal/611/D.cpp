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

const int max_n = 5055, mod = 1000000007;

int n, z[max_n][max_n], sum[max_n][max_n];
string s;

void get_z_function(int st) {
    z[st][st] = 0;
    int l = st, r = st;
    for (int i = st + 1; i < s.length(); ++i) {
        z[st][i] = 0;
        if (i <= r) {
            z[st][i] = min(z[st][st + i - l], r - i + 1);
        }
        while (i + z[st][i] < s.length() && s[i + z[st][i]] == s[st + z[st][i]]) {
            ++z[st][i];
        }
        if (i + z[st][i] - 1 > r) {
            r = i + z[st][i] - 1;
            l = i;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        get_z_function(i);
        /*cout << i << " : ";
        for (int j = 0; j < s.length(); ++j) {
            cout << z[i][j] << " ";
        }
        cout << endl;*/
    }
    for (int i = 0; i < s.length(); ++i) {
        for (int len = 1; len <= i + 1; ++len) {
            if (len == i + 1) {
                sum[i][len] = 1;
            } else if (s[i - len + 1] != '0') {
                sum[i][len] = sum[i - len][len - 1];
                int poz = i - 2 * len + 1;
                if (poz >= 0) {
                    int q = z[poz][poz + len];
                    //if (i == 7 && len == 4) cout << poz << " " << poz + len << " " << q << endl;
                    if (poz + q < poz + len && s[poz + q] < s[poz + len + q]) {
                        sum[i][len] += sum[poz + len - 1][len] - sum[poz + len - 1][len - 1];
                        sum[i][len] %= mod;
                        if (sum[i][len] < 0) {
                            sum[i][len] += mod;
                        }
                    }
                }
            }
            sum[i][len] += sum[i][len - 1];
            sum[i][len] %= mod;
        }
        for (int len = i + 2; len <= n; ++len) {
            sum[i][len] = sum[i][len - 1];
        }
        /*cout << i << " : ";
        for (int len = 1; len <= n; ++len) {
            cout << sum[i][len] - sum[i][len - 1] << " ";
        }
        cout << endl;*/
    }
    cout << sum[n - 1][n] << endl;
    return 0;
}