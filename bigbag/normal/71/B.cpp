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

const int max_n = 111, inf = 111111111;

int n, k;
double t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> t;
    t /= 100;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            double sum = i * k + j;
            if (sum / n / k <= t && t < (sum + 1) / n / k) {
                for (int q = 0; q < i; ++q) {
                    cout << k << ' ';
                }
                cout << j << ' ';
                for (int q = i + 1; q < n; ++q) {
                    cout << 0 << ' ';
                }
                return 0;
            }
        }
    }
    return 0;
}