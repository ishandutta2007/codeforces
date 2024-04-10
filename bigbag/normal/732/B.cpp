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

const int max_n = 555, inf = 1111111111;

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] + a[i] < k) {
            res += k - a[i - 1] - a[i];
            a[i] += k - a[i - 1] - a[i];
        }
    }
    cout << res << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}