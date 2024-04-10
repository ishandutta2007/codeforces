#include <map>
#include <set>
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

const int max_n = 2222, inf = 1111111111;

int n, b, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> b;
    int k = b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = b;
    for (int i = 0; i + 1 < n; ++i) {
        int d = b / a[i];
        int max1 = 0;
        for (int j = i + 1; j < n; ++j) {
            max1 = max(max1, a[j]);
        }
        ans = max(ans, b % a[i] + d * max1);
    }
    cout << ans;
    return 0;
}