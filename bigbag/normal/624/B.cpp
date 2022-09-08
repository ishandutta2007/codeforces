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

const int max_n = 33, inf = 1111111111;

int n, a[max_n];
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    a[n] = inf;
    for (int i = n - 1; i >= 0; --i) {
        a[i] = max(0, min(a[i], a[i + 1] - 1));
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}