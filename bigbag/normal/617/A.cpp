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

const int max_n = 1111111, inf = 1111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1];
        if (i >= 2) a[i] = min(a[i], a[i - 2]);
        if (i >= 3) a[i] = min(a[i], a[i - 3]);
        if (i >= 4) a[i] = min(a[i], a[i - 4]);
        if (i >= 5) a[i] = min(a[i], a[i - 5]);
        ++a[i];
    }
    cout << a[n] << endl;
    return 0;
}