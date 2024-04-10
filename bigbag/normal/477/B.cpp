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

const int max_n = 63333, inf = 1111111111;

int n, k, ans[max_n][4];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    cout << (6 * n - 1) * k << endl;
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d\n", k * (6 * i + 1), k * (6 * i + 2), k * (6 * i + 3), k * (6 * i + 5));
    }
    return 0;
}