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

const int max_n = 1111111, inf = 1000000007;

int n, k, a[max_n], pw[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k == 0) {
        long long ans = 1;
        for (int i = 1; i < n; ++i) {
            ans = (ans * n) % inf;
        }
        cout << ans << endl;
        return 0;
    }
    if (k == 1) {
        long long ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = (ans * n) % inf;
        }
        cout << ans << endl;
        return 0;
    }
    pw[0] = 1;
    for (int i = 1; i < n; ++i) {
        pw[i] = (1LL * pw[i - 1] * k) % n;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = (1LL * i * k) % n;
    }
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            int cnt = 1, v = i, last;
            while (used[v] == 0) {
                used[v] = cnt;
                ++cnt;
                last = v;
                v = a[v];
            }
            cnt = used[last] - used[v] + 1;
            //cout << cnt << endl;
            if (pw[cnt] == 1) {
                ans = (ans * n) % inf;
            }
        }
    }
    cout << ans << endl;
    return 0;
}