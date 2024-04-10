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

const int max_n = 111111, inf = 1111111111;

long long n, m, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum1 += a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sum2 += b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    long long ans1 = sum1, ans2 = sum2;
    for (int i = 0; i + 1 < m; ++i) {
        ans1 += min(sum1, b[i]);
    }
    for (int i = 0; i + 1 < n; ++i) {
        ans2 += min(sum2, a[i]);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}