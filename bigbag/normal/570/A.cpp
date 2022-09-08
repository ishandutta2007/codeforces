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

const int max_n = 111, inf = 1111111111;

int n, m, a[max_n], b[max_n];

int get() {
    int mx = -1, res;
    for (int j = 0; j < m; ++j) {
        if (mx < b[j]) {
            mx = b[j];
            res = j;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[j];
        }
        a[i] = get();
        //cout << a[i] << endl;
    }
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; ++i) {
        ++b[a[i]];
    }
    cout << get() + 1 << endl;
    return 0;
}