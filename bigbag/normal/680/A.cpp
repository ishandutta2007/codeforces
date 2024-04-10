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

int n = 5, sum, mx, a[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        ++cnt[a[i]];
    }
    sort(a, a + n);
    for (int i = 1; i < max_n; ++i) {
        if (cnt[i] > 1) {
            mx = max(mx, min(cnt[i], 3) * i);
        }
    }
    cout << sum - mx << endl;
    return 0;
}