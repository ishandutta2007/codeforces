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

int n, k, a[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    a[k] = k + 1;
    for (int i = k; i > 0; --i) {
        used[a[i]] = 1;
        if (a[i] - i >= 1 && used[a[i] - i] == 0) {
            a[i - 1] = a[i] - i;
        } else {
            a[i - 1] = a[i] + i;
        }
    }
    for (int i = k + 1; i < n; ++i) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";

    }
    return 0;
}