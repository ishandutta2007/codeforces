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

const int max_n = 1111, inf = 1111111111;

int n, ans, a[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                if (used[j] == 0 && a[j] <= ans) {
                    ++ans;
                    used[j] = 1;
                }
            }
        } else {
            for (int j = n - 1; j >= 0; --j) {
                if (used[j] == 0 && a[j] <= ans) {
                    ++ans;
                    used[j] = 1;
                }
            }
        }
        if (ans == n) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}