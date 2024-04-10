#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

int n, d, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && abs(a[i] - a[j]) <= d) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}