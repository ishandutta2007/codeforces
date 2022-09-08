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

const int max_n = 1111111, inf = 1111111111;

int n, m, z[max_n], a[max_n];
string s;

void get_z_function() {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
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
    cin >> s;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    get_z_function();
    int poz = 0, cnt = 0, last = -inf;
    for (int i = 1; i <= n; ++i) {
        if (poz < m && a[poz] == i) {
            if (poz == 0) {
            } else {
                if (last + s.length() - 1 >= a[poz]) {
                    int poz = i - last;
                    if (z[poz] + poz < s.length()) {
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
            last = a[poz];
            ++poz;
        } else if (last + ((int) s.length()) - 1 < i) {
            ++cnt;
        }
    }
    long long Ans = 1;
    for (int i = 0; i < cnt; ++i) {
        Ans *= 26;
        Ans %= 1000000007;
    }
    cout << Ans << endl;
    return 0;
}