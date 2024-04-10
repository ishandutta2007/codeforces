#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222, max_x = 66666, inf = 1011111111;
const int max_l = 15;

int n, m, f[max_n], len[max_n];
string s[max_n], l[max_n], r[max_n];
bitset<max_x> b[max_n];

void proc1(int i, const string &s) {
    for (int j = 0; j < s.length(); ++j) {
        int x = 1;
        for (int k = j; k < j + max_l && k < s.length(); ++k) {
            x = x * 2 + s[k] - '0';
            b[i][x] = 1;
            //cout << x << " ";
        }
    }
}

int solve(int i) {
    int ans = max_l;
    for (int k = 1; k <= max_l; ++k) {
        int mn = (1 << k);
        int mx = (1 << (k + 1)) - 1;
        int f = 1;
        for (int j = mn; j <= mx; ++j) {
            if (b[i][j] == 0) {
                f = 0;
                break;
            }
        }
        if (f == 0) {
            ans = k - 1;
            break;
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        f[i] = 0;
        len[i] = s[i].length();
        proc1(i, s[i]);
    }
    cin >> m;
    for (int i = n; i < n + m; ++i) {
        int num1, num2;
        cin >> num1 >> num2;
        --num1;
        --num2;
        if (f[num1] || f[num2]) {
            f[i] = 1;
            if (f[num1]) {
                if (f[num2]) {
                    l[i] = l[num1];
                    r[i] = r[num2];
                } else {
                    l[i] = l[num1];
                    string q = r[num1] + s[num2];
                    r[i] = q.substr(q.length() - max_l, max_l);
                }
            } else {
                l[i] = (s[num1] + l[num2]).substr(0, max_l);
                r[i] = r[num2];
            }
        } else if (len[num1] + len[num2] > 2 * max_l) {
            f[i] = 1;
            s[i] = s[num1] + s[num2];
            l[i] = s[i].substr(0, max_l);
            r[i] = s[i].substr(s[i].length() - max_l);
        } else {
            len[i] = len[num1] + len[num2];
            s[i] = s[num1] + s[num2];
        }
        //cout << i << ": " << f[i] << "  l = " << l[i] << ", r = " << r[i] << ", s = " << s[i] << endl;
        if (f[i] == 0 || (f[i] == 1 && f[num1] == 0 && f[num2] == 0)) {
            proc1(i, s[i]);
        } else {
            string mid;
            if (f[num1]) {
                if (f[num2]) {
                    mid = r[num1] + l[num2];
                } else {
                    mid = r[num1] + s[num2];
                }
            } else {
                mid = s[num1] + l[num2];
            }
            b[i] = b[num1] | b[num2];
            //cout << "#" << mid << endl;
            proc1(i, mid);
        }
        cout << solve(i) << endl;
    }
    return 0;
}