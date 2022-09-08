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

const int max_lev = 18, max_m = 111, inf = 111111111;

string s;
long long p, dp[1 << max_lev][max_m], used[11];;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> p;
    dp[0][0] = 1;
    for (int i = 0; i < (1 << s.length()); ++i) {
        for (int j = 0; j < s.length(); ++j) {
            for (int k = 0; k < p; ++k) {
                if (get_bit(i, j) == 0) {
                    if (i != 0 || s[j] != '0') {
                        dp[i | (1 << j)][(k * 10 + s[j] - '0') % p] += dp[i][k];
                    }
                }
            }
        }
    }
    long long q = 1;
    for (int i = 0; i < s.length(); ++i) {
        ++used[s[i] - '0'];
        q *= used[s[i] - '0'];
    }
    cout << dp[(1 << s.length()) - 1][0] / q << endl;
    return 0;
}