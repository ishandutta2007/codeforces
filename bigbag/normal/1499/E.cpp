/**
 *  created: 18/03/2021, 17:27:24
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, mod = 998244353;

void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int ans, dp[max_n][max_n][2];
string a, b;

void proc(string s, int len) {
    for (int l = 0; l < s.size(); ++l) {
        for (int r = l; r < s.size(); ++r) {
            if (r > l && s[r] == s[r - 1]) {
                break;
            }
            inc(ans, mod - len);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            inc(dp[i + 1][j][0], 1);
            inc(dp[i][j + 1][1], 1);
        }
    }
    for (int i = 0; i <= a.size(); ++i) {
        for (int j = 0; j <= b.size(); ++j) {
            for (int f = 0; f < 2; ++f) {
                if (!dp[i][j][f]) {
                    continue;
                }
                inc(ans, dp[i][j][f]);
                char c;
                if (f == 0) {
                    c = a[i - 1];
                } else {
                    c = b[j - 1];
                }
                //cout << "#" << i << " " << j << " " << f << ": " << dp[i][j][f] << ", c = " << c << endl;
                for (int nf = 0; nf < 2; ++nf) {
                    if ((nf == 0 && i == a.size()) || (nf == 1 && j == b.size())) {
                        continue;
                    }
                    char nc;
                    int ni = i, nj = j;
                    if (nf == 0) {
                        nc = a[i];
                        ++ni;
                    } else {
                        nc = b[j];
                        ++nj;
                    }
                    if (nc != c) {
                        //cout << "-> " << ni << " " << nj << " " << nf << "   " << c << " " << nc << endl;
                        inc(dp[ni][nj][nf], dp[i][j][f]);
                    }
                }
            }
        }
    }
    proc(a, b.size());
    proc(b, a.size());
    cout << ans << "\n";
    return 0;
}