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

int n, a[max_n], used[max_n];
vector<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            int v = i, len = 0;
            while (used[v] == 0) {
                used[v] = 1;
                v = a[v];
                ++len;
            }
            if (v != i) {
                cout << -1 << endl;
                return 0;
            }
            if (len % 2 == 0) {
                len /= 2;
            }
            q.push_back(len);
            long long g = __gcd(1LL * len, ans);
            ans /= g;
            ans *= len;
        }
    }
    cout << ans << endl;
    return 0;
}