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

const int max_n = 222;

int n, last, a[max_n], b[max_n], used[max_n];
set<int> q;
long long ans = 1;

long long lcm(long long x, long long y) {
    return (x / __gcd(x, y)) * y;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        b[i] = a[i];
        q.insert(a[i]);
    }
    for (int i = 1; i < 10000; ++i) {
        int sz = q.size();
        q.clear();
        for (int j = 0; j < n; ++j) {
            b[j] = a[b[j]];
            q.insert(b[j]);
        }
        if (q.size() < sz) {
            last = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        used[b[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == 1) {
            int len = 1;
            int x = a[i];
            while (x != i) {
                x = a[x];
                ++len;
            }
            ans = lcm(ans, len);
        }
    }
    if (ans >= last + 1) {
        cout << ans << endl;
        return 0;
    }
    long long m = (last + 1) / ans;
    if (m * ans <= last) {
        ++m;
    }
    cout << m * ans << endl;
    return 0;
}