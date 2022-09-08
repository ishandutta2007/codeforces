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

const int max_n = 333333, inf = 1111111111;

long long n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    long long sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    for (int i = 0; i + 1 < n; ++i) {
        ans += sum + a[i];
        sum -= a[i];
    }
    cout << ans + a[n - 1] << endl;
    return 0;
}