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

const int max_n = 111, inf = 1011111111;

int n, a[6], b[6], cnt[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++a[x];
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++b[x];
    }
    int ans = 0;
    for (int i = 1; i < 6; ++i) {
        if ((a[i] + b[i]) % 2) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] > b[i]) {
            cnt[0] += abs(a[i] - b[i]) / 2;
        } else {
            cnt[1] += abs(a[i] - b[i]) / 2;
        }
    }
    if (cnt[0] != cnt[1]) {
        cout << -1 << endl;
    } else {
        cout << cnt[0] << endl;
    }
    return 0;
}