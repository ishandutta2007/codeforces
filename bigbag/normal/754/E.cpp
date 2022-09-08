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

const int max_n = 405, inf = 1011111111;

int n, m, r, c;
short int z[max_n][max_n][3 * max_n];
string s[max_n], t[max_n];

string read() {
    char s[max_n];
    scanf("%s", s);
    return s;
}

bool eq(char c1, char c2) {
    return c1 == '?' || c1 == c2;
}

void get_z_function(const string &s, short int z[]) {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], (short int) (r - i + 1));
        }
        while (i + z[i] < s.length() && eq(s[z[i]], s[i + z[i]])) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        s[i] = read();
        while (s[i].length() < 888) {
            s[i] += s[i];
        }
        s[i] = s[i].substr(0, 808);
    }
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i) {
        t[i] = read();
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r; ++j) {
            get_z_function(t[j] + s[i], z[i][j]);
        }
    }
    if (0) {
        for (int i = 0; i < 10; ++i) {
            cout << z[0][0][i] << " ";
        }
        cout << endl;
        //cout << z[0][0][4] << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int f = 1;
            for (int k = 0; k < r; ++k) {
                if (z[(i + k) % n][k][j + c] < c) {
                    f = 0;
                    break;
                }
            }
            printf("%d", f);
        }
        printf("\n");
    }
    return 0;
}