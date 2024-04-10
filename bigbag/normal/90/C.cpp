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

const long long max_n = 11111, inf = 1111111111;

long long n, m, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    long long sum = inf;
    for (int i = 0; i < n; i += 2) {
        sum = min(sum, a[i]);
    }
    long long x = (n + 1) / 2;
    x = (m / x) * k;
    cout << min(sum, x) << endl;
    return 0;
}