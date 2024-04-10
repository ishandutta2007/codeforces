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

const int max_n = 2222222, inf = 1111111111;

int n, z[3][max_n], p[3][max_n];
string a, b, ra, rb, q1, q2, q3;

void get_z_function(string s, int num) {
    z[num][0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[num][i] = 0;
        if (i <= r) {
            z[num][i] = min(z[num][i - l], r - i + 1);
        }
        while (i + z[num][i] < s.length() && s[i + z[num][i]] == s[z[num][i]]) {
            ++z[num][i];
        }
        if (i + z[num][i] - 1 > r) {
            r = i + z[num][i] - 1;
            l = i;
        }
    }
}

void get_prefix_function(string s, int num) {
    p[num][0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        p[num][i] = p[num][i - 1];
        while (s[i] != s[p[num][i]] && p[num][i] > 0) {
            p[num][i] = p[num][p[num][i] - 1];
        }
        if (s[i] == s[p[num][i]]) {
            ++p[num][i];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    getline(cin, a);
    getline(cin, b);
    n = a.length();
    if (a.length() != b.length() || a.length() == 1) {
        cout << "-1 -1" << endl;
        return 0;
    }
    ra = a;
    rb = b;
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    q1 = rb;
    q1 += 127;
    q1 += a;
    get_z_function(q1, 0);
    q2 = ra;
    q2 += 127;
    q2 += b;
    get_prefix_function(q2, 1);
    q3 = b;
    q3 += 127;
    q3 += a;
    get_z_function(q3, 2);
    for (int i = n - 2; i >= 0; --i) {
        //cout << i << " " << z[0][n + 1] << endl;
        if (z[0][n + 1] >= i + 1) {
            //cout << i << endl;
            int len = p[1][n + n - i - 2 + 1];
            int j = max(i + 1, n - len);
            if (i + 1 == j) {
                cout << i << " " << j << endl;
                return 0;
            }
            if (z[2][n + 1 + i + 1] >= j - 1 - i) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}