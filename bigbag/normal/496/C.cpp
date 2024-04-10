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

const int max_n = 1011, inf = 1111111111;

int n, m, f[max_n];
string s[max_n];

bool ok(int poz) {
    for (int j = 0; j + 1 < n; ++j) {
        if (f[j] == 1 && s[j][poz] > s[j + 1][poz]) {
            return false;
        }
    }
    for (int j = 0; j + 1 < n; ++j) {
        if (f[j] == 1 && s[j][poz] < s[j + 1][poz]) {
            f[j] = 0;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        f[i] = 1;
    }
    f[n - 1] = 0;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (ok(i)) {

        } else {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}