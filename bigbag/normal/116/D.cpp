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

const int max_n = 222, inf = 1111111111;

int n, m, last = -1, ans, l[max_n], r[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        l[i] = inf;
        r[i] = -1;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'W') {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
        if (l[i] != inf) {
            last = i;
        }
    }
    if (last == -1) {
        cout << 0 << endl;
        return 0;
    }
    int poz = 0;
    for (int i = 0; i <= last; ++i) {
        if (r[i] == -1) {
            continue;
        }
        if (i % 2 == 0) {
            if (l[i] < poz) {
                ans += poz - l[i];
                poz = l[i];
            }
            ans += r[i] - poz;
            poz = r[i];
        } else {
            if (r[i] > poz) {
                ans += r[i] - poz;
                poz = r[i];
            }
            ans += poz - l[i];
            poz = l[i];
        }
    }
    cout << ans + last << endl;
    return 0;
}